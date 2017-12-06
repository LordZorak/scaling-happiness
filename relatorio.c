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
			Cliente clienteAtendido = desempilharCliente(i);
			inserirClienteNaLista(clienteAtendido);
		}
		i++;
	}
}

// Função que aloca os dados do cliente necessários para a saida em um elemento da lista
Relatorio* alocaNovoElemento(Cliente novoCliente){
	Relatorio *novoRegistro;
	novoRegistro = (Relatorio *) malloc (1 * sizeof(Relatorio));
	novoRegistro->codigo = novoCliente.codigo;
	novoRegistro->quantidadeOperacoes = 0;
	novoRegistro->saldoCliente = 0;
	novoRegistro->anterior =  NULL;
	novoRegistro->proximo = NULL;
	return novoRegistro;
}

// Função que efetua as operações, e atualiza sua quantidade, do cliente  
void efetuarOperacoes(Relatorio *relatorioFinal, Cliente clienteAtendido){
	if(clienteAtendido.operacao == 0)
		relatorioFinal->saldoCliente += clienteAtendido.valor;
	else
		relatorioFinal->saldoCliente -= clienteAtendido.valor;
	relatorioFinal->quantidadeOperacoes++;
}	

// Função que verifica se um cliente já existe na lista
Relatorio* pesquisaCliente(Cliente clienteAtendido){
	Relatorio *ultimo;
	ultimo = mRelatorios.cabeca->anterior;
	Relatorio *clienteNaoEncontrado = mRelatorios.cabeca;
	if(clienteAtendido.codigo <= ultimo->codigo){
		Relatorio *clienteEncontrado = mRelatorios.cabeca->proximo;
		while(clienteEncontrado->codigo < clienteAtendido.codigo){
			clienteEncontrado = clienteEncontrado->proximo;
		}
		return clienteEncontrado;
	}else{
		return clienteNaoEncontrado;
	}
}

// Função que insere um cliente na lista caso não exista um registro anterior. Caso exista o atualiza
void inserirClienteNaLista(Cliente clienteAtendido){
	Relatorio *ponteiro = pesquisaCliente(clienteAtendido);
	if(ponteiro->codigo!=clienteAtendido.codigo){
		Relatorio *anterior = ponteiro->anterior;
		Relatorio *novoCliente = alocaNovoElemento(clienteAtendido);
		efetuarOperacoes(novoCliente, clienteAtendido);
		novoCliente->anterior = anterior;
		novoCliente->proximo= ponteiro;
		anterior->proximo = novoCliente;
		ponteiro->anterior = novoCliente;
		mRelatorios.contadorClientesDistintos++;
	}else{
		efetuarOperacoes(ponteiro, clienteAtendido);
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
