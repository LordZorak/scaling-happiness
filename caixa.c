#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cliente.h"
#include "caixa.h"

// Declaração de um registro pra gerenciar a fila de clientes
typedef struct cliente{
	int codigo;
	int operacao;
	int valor;
} Cliente;

// Declaração de um registro para gerenciar as pilhas de caixas
typedef struct Caixa{
	Cliente *pilhaClientes;
	int topo;
	int tamanho;
}Caixa;

/* Declaração de um registro para facilitara a manipulação dos caixas 
 * Para não sobrecarregar um caixa, adotamos como regra de negócio que ele adiciona um cliente em um caixa por vez 
 * verificando onde o último cliente foi inserido */
typedef struct bateria_caixas{
	Caixa *caixas;
	int ultimo_inserido;
}bateria_caixas;

// Variáveis globais 
bateria_caixas meus_caixas;
int numeroCaixas;
int numeroClientes; 
Cliente *PilhaClientes;

/* Função que define a quantidade e capacidade máxima dos caixas, 
 * respeitando o limite teto da capacidade de (N/M) e o limite de quantidade de M caixas
 * e definindo os controladores das pilhas de cada caixa (topo) para começarem em 0 */
void definirPilha(int n, int m){ 
	numeroCaixas = m;
	numeroClientes = n;
	meus_caixas.caixas = (Caixa*) malloc (m * sizeof(Caixa)); 
	int i;
	for(i=0;i<m;i++){
		int tam = ceil(n/m) + 1;
		meus_caixas.caixas[i].pilhaClientes = (Cliente *) malloc(tam * sizeof(Cliente)); 
		meus_caixas.caixas[i].topo = 0; 
		meus_caixas.caixas[i].tamanho = tam;
	}
	meus_caixas.ultimo_inserido = 0;
}

// Função pra atender clientes adicionando o cliente no topo da pilha do próximo caixa livre sem a capacidade máxima atingida
void atenderCliente(Cliente cliente){
	int topoAtual;
	if (limiteDeCaixas(meus_caixas.ultimo_inserido))
			meus_caixas.ultimo_inserido = 0;

	if (pilhaEstaCheia(meus_caixas.caixas[meus_caixas.ultimo_inserido].topo))
		meus_caixas.ultimo_inserido++; 
	
	topoAtual = meus_caixas.caixas[meus_caixas.ultimo_inserido].topo += 1; 
		
	meus_caixas.caixas[meus_caixas.ultimo_inserido].pilhaClientes[topoAtual] = cliente;
	meus_caixas.ultimo_inserido++;
}

// Função que retira os dados dos clientes atendidos em determinado caixa para a elaboração do relatório final
Cliente desempilharCliente(int CaixaASerDesempilhado){
	Cliente valorRecuperado; 
	
	if(!pilhaEstaVazia(meus_caixas.caixas[CaixaASerDesempilhado].topo)){
		valorRecuperado = meus_caixas.caixas[CaixaASerDesempilhado].pilhaClientes[meus_caixas.caixas[CaixaASerDesempilhado].topo];
		meus_caixas.caixas[CaixaASerDesempilhado].topo -= 1;
	}
	return valorRecuperado;
}

// Função que verifica se o caixa atual está no limite de M caixas
int limiteDeCaixas(int CaixaAtual){
	return (CaixaAtual == numeroCaixas);
}

// Função que verifica se o caixa atual está dentro da capacidade máxima de N/M clientes atendidos
int pilhaEstaCheia(int topo){
	return (topo > meus_caixas.caixas[meus_caixas.ultimo_inserido].tamanho);
}

// Função que verifica se o caixa atual não contém nenhum atendimento
int pilhaEstaVazia(int topo){
	return (topo < 1);
}

// Função que retorna o topo da fila selecionada
int getTopo(int posicao){
	return meus_caixas.caixas[posicao].topo;
}
