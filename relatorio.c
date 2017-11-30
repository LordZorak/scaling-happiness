#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"
#include "relatorio.h"

typedef struct dados{
	Cliente cliente;	
	int quantidadeOperacoes;
	int saldoCliente;
}DadosCliente;

typedef struct relatorio{
	DadosCliente PilhaCliente;
	int contadorClientesDistintos;
	struct relatorio * anterior;
	struct relatorio * proximo;
}Relatorio;

Relatorio relatorioFinal;
Relatorio *ultimo, *posterior, *antecessor;

void processarOperacoes(){
	relatorioFinal.contadorClientesDistintos = 0;
	int i = 0;
	while (!LimiteDeCaixas(i)) {
		while (!PilhaEstaVazia(getTopo(i)){
			Cliente novo = desempilharCliente(i); 
			inserirClienteNaLista(novo);
		}
		i++;
	}
}
//Pesquisar o cliente a ser recebido 
//Se encontrado atualizar dados de saldo(1 = saque(-) ou 0 = deposito(+)) e contadorOperacoes++
//Senao inserir de modo crescente pelo id e contadorClientesDistintos++

Relatorio* alocaNovoElemento(Cliente cliente){
	novo = (Relatorio *)malloc(1*sizeof(Relatorio));
	novo.PilhaCliente.cliente = cliente;
	novo.PilhaCliente.quantidadeOperacoes = 0;
	novo.PilhaCliente.saldoCliente = 0;
	novo.contadorClientesDistintos++;
	novo.anterior =  NULL;
	novo.proximo = NULL;
	return novo;
}

void efetuarOperacoes(Cliente cliente){
	if(relatorioFinal.PilhaCliente.cliente.operacao == 0){
		relatorioFinal.PilhaCliente.saldoCliente += relatorioFinal.PilhaCliente.cliente.valor; 
	}else{
		relatorioFinal.PilhaCliente.saldoCliente -= relatorioFinal.PilhaCliente.cliente.valor;
	}
	relatorioFinal.PilhaCliente.quantidadeOperacoes++;
}	

Relatorio * pesquisaCliente(Cliente cliente){
	ultimo = relatorioFinal.anterior;
	if (cliente.codigo <= ultimo.PilhaCliente.cliente.codigo){
		posterior = relatorioFinal.proximo; 
		while(posterior.PilhaCliente.cliente.codigo < cliente.codigo){
			posterior = posterior.proximo;  
		}
		return posterior;
	}else{
		return relatorioFinal;
	}
	return NULL;
}

void inserirClienteNaLista(Cliente cliente){
	posterior = pesquisaCliente(cliente);
	if(posterior == relatorioFinal || posterior.PilhaCliente.cliente.codigo != cliente.codigo){
		antecessor = posterior.anterior;
		Relatorio novo = alocaNovoElemento(cliente); 
		novo.anterior = antecessor;
		novo.proximo = posterior;
		antecessor->proximo = novo;
		posterior->anterior = novo;
	} else{
		efetuarOperacoes(cliente);
	}
}
