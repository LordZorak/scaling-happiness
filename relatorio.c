#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"
#include "relatorio.h"

typedef struct cliente{
	int codigo;
	int operacao;
	int valor;
} Cliente;

typedef struct relatorio{
	int codigo;	
	int quantidadeOperacoes;
	int saldoCliente;
	struct relatorio * anterior;
	struct relatorio * proximo;
}Relatorio;

struct Relatorios{
	Relatorio *cabeca;
	int contadorClientesDistintos; 
	}mRelatorios;

void processarOperacoes(){
	int i = 0;
	//printf(" PAASSSSUIEN POORIA %d", LimiteDeCaixas(i));
	mRelatorios.cabeca = (Relatorio *)malloc(1*sizeof(Relatorio));
	mRelatorios.cabeca->codigo = 0;
	mRelatorios.cabeca->quantidadeOperacoes = 0;
	mRelatorios.cabeca->saldoCliente = 0;
	mRelatorios.cabeca->anterior =  mRelatorios.cabeca;
	mRelatorios.cabeca->proximo = mRelatorios.cabeca;
	mRelatorios.contadorClientesDistintos=0;
	while (!LimiteDeCaixas(i)) {
		while (newPilhaVazia(i)){
			Cliente novo = desempilharCliente(i);
			printf("*%d-%d*\n", novo.codigo,i);
			inserirClienteNaLista(novo);
		}
		i++;
	}
}
//Pesquisar o cliente a ser recebido 
//Se encontrado atualizar dados de saldo(1 = saque(-) ou 0 = deposito(+)) e contadorOperacoes++
//Senao inserir de modo crescente pelo id e contadorClientesDistintos++

Relatorio* alocaNovoElemento(Cliente cliente){
	Relatorio *novo;
	novo = (Relatorio *)malloc(1*sizeof(Relatorio));
	novo->codigo = cliente.codigo;
	novo->quantidadeOperacoes = 0;
	novo->saldoCliente = 0;
	novo->anterior =  NULL;
	novo->proximo = NULL;
	return novo;
}

void efetuarOperacoes(Relatorio *rel, Cliente cliente){
	if(cliente.operacao == 0){
		rel->saldoCliente += cliente.valor; 
	}else{
		rel->saldoCliente -= cliente.valor;
	}
	rel->quantidadeOperacoes++;
}	

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

void inserirClienteNaLista(Cliente cliente){
	Relatorio *ponteiro = pesquisaCliente(cliente);
	if(ponteiro == mRelatorios.cabeca->anterior || ponteiro->codigo!=cliente.codigo){
		Relatorio *anterior = ponteiro->anterior;
		Relatorio *novo = alocaNovoElemento(cliente);
		novo->quantidadeOperacoes++;
		efetuarOperacoes(novo, cliente);
		novo->anterior = anterior;
		novo->proximo= ponteiro;
		anterior->proximo = novo;
		ponteiro->anterior = novo;
	}else{
		ponteiro->quantidadeOperacoes++;
		efetuarOperacoes(ponteiro, cliente);
	}		
}

void listar(){
	Relatorio *auxiliar = mRelatorios.cabeca->proximo;
	//while (auxiliar!=mRelatorios.cabeca){
	printf ("%d %d %d \n", auxiliar->codigo, auxiliar->quantidadeOperacoes, auxiliar->saldoCliente);
	//	auxiliar = auxiliar->proximo;  
	//}
}
