#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"
#include "relatorio.h"

// Declaração de um registro Cliente pra facilitar a manipulação de clientes
typedef struct cliente{
	int codigo;
	int operacao;
	int valor;
} Cliente;

// Declaração de um registro Relatorio para facilitar a exibição da resposta final
typedef struct relatorio{
	long long int codigo;	
	long long int quantidadeOperacoes;
	long long int saldoCliente;
	struct relatorio * anterior;
	struct relatorio * proximo;
}Relatorio;

// Declaração de um registro para gerenciar a lista do relatório
struct Relatorios{
	Relatorio *cabeca;
	int contadorClientesDistintos; 
}mRelatorios;
 
// Função de alocação de uma lista relatório na memória
void definirLista(){
	mRelatorios.cabeca = (Relatorio *) malloc(1 * sizeof(Relatorio));
	mRelatorios.cabeca->codigo = 0;
	mRelatorios.cabeca->quantidadeOperacoes = 0;
	mRelatorios.cabeca->saldoCliente = 0;
	mRelatorios.cabeca->anterior =  mRelatorios.cabeca;
	mRelatorios.cabeca->proximo = mRelatorios.cabeca;
	mRelatorios.contadorClientesDistintos = 0;
}

// Função que desempilha todos os caixas, um por vez, e insere os dados dos clientes na lista 
void processarOperacoes(){
	int i = 0;
	definirLista();
	while (!limiteDeCaixas(i)) {
		while (getTopo(i)){
			Cliente novo = desempilharCliente(i);
			inserirClienteNaLista(novo);
		}
		i++;
	}
}

// Função que aloca os dados do cliente necessários para a saida em um elemento da lista
Relatorio* alocaNovoElemento(Cliente cliente){
	Relatorio *novo;
	novo = (Relatorio *) malloc (1 * sizeof(Relatorio));
	novo->codigo = cliente.codigo;
	novo->quantidadeOperacoes = 0;
	novo->saldoCliente = 0;
	novo->anterior =  NULL;
	novo->proximo = NULL;
	return novo;
}

// Função que efetua as operações, e atualiza sua quantidade, do cliente  
void efetuarOperacoes(Relatorio *rel, Cliente cliente){
	if(cliente.operacao == 0)
		rel->saldoCliente += cliente.valor;
	else
		rel->saldoCliente -= cliente.valor;
	rel->quantidadeOperacoes++;
}	

// Função que verifica se um cliente já existe na lista
Relatorio* pesquisaCliente(Cliente cliente){
	Relatorio *ultimo;
	ultimo = mRelatorios.cabeca->anterior;
	Relatorio *n_encontrou = mRelatorios.cabeca;
	if(cliente.codigo <= ultimo->codigo){
		Relatorio *ponteiro = mRelatorios.cabeca->proximo;
		while(ponteiro->codigo < cliente.codigo){
			ponteiro = ponteiro->proximo;
		}
		return ponteiro;
	}else{
		return n_encontrou;
	}
}

// Função que insere um cliente na lista caso não exista um registro anterior. Caso exista o atualiza
void inserirClienteNaLista(Cliente cliente){
	Relatorio *ponteiro = pesquisaCliente(cliente);
	if(ponteiro->codigo!=cliente.codigo){
		Relatorio *anterior = ponteiro->anterior;
		Relatorio *novo = alocaNovoElemento(cliente);
		efetuarOperacoes(novo, cliente);
		novo->anterior = anterior;
		novo->proximo= ponteiro;
		anterior->proximo = novo;
		ponteiro->anterior = novo;
		mRelatorios.contadorClientesDistintos++;
	}else{
		efetuarOperacoes(ponteiro, cliente);
	}		
}

// Função que enumera todos os registros da lista, mostrando o relatório final da agência 
void listar(){
	Relatorio *auxiliar = mRelatorios.cabeca->proximo;
	printf("%d\n", mRelatorios.contadorClientesDistintos);
	while (auxiliar!=mRelatorios.cabeca){
		printf ("%lld %lld %lld\n", auxiliar->codigo, auxiliar->quantidadeOperacoes, auxiliar->saldoCliente);
		auxiliar = auxiliar->proximo;  
	}
}
