#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"

// Declaração de um registro pra gerenciar a fila de clientes
typedef struct minhafila{
	Cliente *mFila;
	int frente;
	int retaguarda;
	int tamanho;
}minhafila;

// Declaração de um registro pra facilitar a manipulação de clientes
typedef struct cliente{
	int codigo;
	int operacao;
	int valor;
} Cliente;

// Definição de variáveis globais
minhafila FilaClientes;
int posicaoAtual;

/* Função que define o tamanho da fila, respeitando o limite piso de sqrt(N) 
 * e definindo os controladores da fila (frente e retaguarda) para começarem em 0 */
void definirFila(int n){
	FilaClientes.tamanho = floor(sqrt(n));
	FilaClientes.mFila = (Cliente *) malloc (FilaClientes.tamanho * sizeof(Cliente));
	FilaClientes.frente = 0;
	FilaClientes.retaguarda = 0;
}
		
// Função que verifica se a fila não contém nenhum elemento
int filaEstaVazia(){
	return (FilaClientes.frente == 0);
}

// Função que verifica se a fila está em sua capacidade máxima 
int filaEstaCheia(){
	posicaoAtual = FilaClientes.retaguarda % FilaClientes.tamanho+1;
	return (posicaoAtual == FilaClientes.frente);
}

/* Função que cria um novo registro de Cliente atribuindo os inteiros em seus respectivos campos de registros 
 * e repassa esse novo cliente para a função de inserir esse novo cliente na fila  */
void criarCliente(int codigo, int operacao, int valor){
	Cliente novo;
	novo.codigo = codigo;
	novo.operacao = operacao;
	novo.valor = valor;
	inserirFila(novo);
}

/* Função que insere o cliente na fila, respeitando as regras de uma fila circular.
 * Caso a fila encha, no decorrer do programa, o primeiro cliente da fila é removido e inserido na pilha de algum caixa */
void inserirFila(Cliente cliente){
	if(filaEstaCheia()){
		Cliente auxiliar = removerDaFila();
		atenderCliente(auxiliar);
	}
	FilaClientes.retaguarda = posicaoAtual;
	FilaClientes.mFila[FilaClientes.retaguarda-1] = cliente;
	if(filaEstaVazia())
		FilaClientes.frente = 1;
}

// Função que remove o primeiro cliente da fila atualizando os controladores de frente e retaguarda da fila 
Cliente removerDaFila(){
	Cliente cliente;
	if(!filaEstaVazia()){
		cliente = FilaClientes.mFila[FilaClientes.frente-1];
		if(FilaClientes.frente == FilaClientes.retaguarda)
			FilaClientes.retaguarda = FilaClientes.frente = 0;
		else
			FilaClientes.frente = FilaClientes.frente % FilaClientes.tamanho +1;
	}
	return cliente;
}

// Função que percorre a fila toda, após o banco chegar em seu limite de n clientes, atendendo os clientes restantes na fila
void processaDados(){
	while(!filaEstaVazia()){
		Cliente auxiliar = removerDaFila();
		atenderCliente(auxiliar);
	}
}
