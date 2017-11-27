#include <stdlib.h>
#include <stdio.h>
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
		meus_caixas.caixas[i].pilhaClientes = (Cliente *) malloc(n/m * sizeof(Cliente)); //aloca cada pilha de cada caixa com n/m;
		meus_caixas.caixas[i].topo = 0; //define o topo de cada pilha como 0
		meus_caixas.caixas[i].tamanho = n/m; //define que o tamanho de cada pilha é n/m
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

	printf("Cliente a ser atendido: %d - %d - %d\n", cliente.codigo, cliente.operacao, cliente.valor);

	if (meus_caixas.ultimo_inserido>=numeroCaixas)
		meus_caixas.ultimo_inserido = 0;	
			
	if (estaCheia(meus_caixas.caixas[meus_caixas.ultimo_inserido].topo))
		meus_caixas.ultimo_inserido++; 			
		
	meus_caixas.caixas[meus_caixas.ultimo_inserido].pilhaClientes->codigo = cliente.codigo; 
	meus_caixas.caixas[meus_caixas.ultimo_inserido].pilhaClientes->operacao = cliente.operacao; 
	meus_caixas.caixas[meus_caixas.ultimo_inserido].pilhaClientes->valor = cliente.valor; 
	meus_caixas.caixas[meus_caixas.ultimo_inserido].topo++;	
	
	printf("Cliente atendido\n Dados salvos: %d - %d - %d\n", meus_caixas.caixas[meus_caixas.ultimo_inserido].pilhaClientes->codigo, meus_caixas.caixas[meus_caixas.ultimo_inserido].pilhaClientes->operacao, meus_caixas.caixas[meus_caixas.ultimo_inserido].pilhaClientes->valor); 
	
	
	meus_caixas.ultimo_inserido++;
}

int estaCheia(int topo){
		if (topo >= meus_caixas.caixas[meus_caixas.ultimo_inserido].tamanho)
			return 1; 
		return 0;
}


