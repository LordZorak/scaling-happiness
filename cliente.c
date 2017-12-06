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
void definirFila(int numeroClientes){
	FilaClientes.tamanho = floor(sqrt(numeroClientes * 1.0));
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
	Cliente novoCliente;
	novoCliente.codigo = codigo;
	novoCliente.operacao = operacao;
	novoCliente.valor = valor;
	inserirFila(novoCliente);
}

/* Função que insere o cliente na fila, respeitando as regras de uma fila circular.
 * Caso a fila encha, no decorrer do programa, o primeiro cliente da fila é removido e inserido na pilha de algum caixa */
void inserirFila(Cliente novoCliente){
	if(filaEstaCheia()){
		Cliente primeiroDaFila = removerDaFila();
		atenderCliente(primeiroDaFila);
	}
	FilaClientes.retaguarda = posicaoAtual;
	FilaClientes.mFila[FilaClientes.retaguarda-1] = novoCliente;
	if(filaEstaVazia())
		FilaClientes.frente = 1;
}

// Função que remove o primeiro cliente da fila atualizando os controladores de frente e retaguarda da fila 
Cliente removerDaFila(){
	Cliente clienteASerAtendido;
	if(!filaEstaVazia()){
		clienteASerAtendido = FilaClientes.mFila[FilaClientes.frente-1];
		if(FilaClientes.frente == FilaClientes.retaguarda)
			FilaClientes.retaguarda = FilaClientes.frente = 0;
		else
			FilaClientes.frente = FilaClientes.frente % FilaClientes.tamanho +1;
	}
	return clienteASerAtendido;
}

// Função que percorre a fila toda, após o banco chegar em seu limite de n clientes, atendendo os clientes restantes na fila
void processaDados(){
	while(!filaEstaVazia()){
		Cliente primeiroDaFila = removerDaFila();
		atenderCliente(primeiroDaFila);
	}
}
