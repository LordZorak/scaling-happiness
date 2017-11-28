#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cliente.h"
#include "caixa.h"


//define estrutura da bateria de caixas. Para n sobrecarregar um caixa, ele adiciona em um por vez
//verificando onde o último foi inserido;
typedef struct bateria_caixas{
	Caixa *caixas;
	int ultimo_inserido;
}bateria_caixas;

bateria_caixas meus_caixas;
int numeroCaixas;
int numeroClientes; 
Cliente *PilhaClientes;

int definir_pilha(int n, int m){
	numeroCaixas = m;
	numeroClientes = n;
	meus_caixas.caixas = (Caixa*) malloc(m* sizeof(Caixa)); //aloca quantos caixas tem
	int i;
	for(i=0;i<m;i++){
		meus_caixas.caixas[i].pilhaClientes = (Cliente *) malloc(ceil(n/m) * sizeof(Cliente)); //aloca cada pilha de cada caixa com n/m;
		meus_caixas.caixas[i].topo = 0; //define o topo de cada pilha como 0
		meus_caixas.caixas[i].tamanho = ceil(n/m); //define que o tamanho de cada pilha é n/m
	}
	meus_caixas.ultimo_inserido = 0;

	if(!meus_caixas.caixas)
		//erro de alocação!
		return 0;
	else
		//alocado com sucesso!
		return 1;
}

void atender_cliente(Cliente cliente){
	
	if (meus_caixas.ultimo_inserido == numeroCaixas)
			meus_caixas.ultimo_inserido = 0;
	printf("Cliente a ser atendido: %d - %d - %d\n", cliente.codigo, cliente.operacao, cliente.valor);
	if (PilhaEstaCheia(meus_caixas.caixas[meus_caixas.ultimo_inserido].topo))
		meus_caixas.ultimo_inserido++; 
	
	printf("Caixa a ser usado: %d\n", meus_caixas.ultimo_inserido); 
	int topo = meus_caixas.caixas[meus_caixas.ultimo_inserido].topo += 1;; 
	printf("No topo %d \n", topo-1);
	meus_caixas.caixas[topo-1].pilhaClientes->codigo = cliente.codigo;
	meus_caixas.caixas[topo-1].pilhaClientes->operacao = cliente.operacao; 
	meus_caixas.caixas[topo-1].pilhaClientes->valor = cliente.valor;
	
	printf("Cliente atendido\nDados salvos: %d - %d - %d em caixa %d\n", meus_caixas.caixas[topo-1].pilhaClientes->codigo, meus_caixas.caixas[topo-1].pilhaClientes->operacao, meus_caixas.caixas[topo-1].pilhaClientes->valor, meus_caixas.ultimo_inserido); 	
	
	meus_caixas.ultimo_inserido++;
}

int PilhaEstaCheia(int topo){
	if (topo > meus_caixas.caixas[meus_caixas.ultimo_inserido].tamanho)
		return 1;
	return 0; 
}
int PilhaEstaVazia(int topo){
	if (topo == 0)
		return 1;
	return 0; 
}


