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


Cliente *PilhaClientes;
int definir_pilha(int n, int m){
	meus_caixas.caixas = (Caixa*) malloc(m* sizeof(Caixa)); //aloca quantos caixas tem
	int i;
	for(i=0;i<m;i++){
		meus_caixas.caixas[i].pilhaClientes = (Cliente *) malloc(n/m * sizeof(Cliente)); //aloca cada pilha de cada caixa com n/m;
		meus_caixas.caixas[i].topo = 0; //define o topo de cada pilha como 0
		meus_caixas.caixas[i].tamanho = n/m; //define que o tamanho de cada pilha é n/m
	}
	if(!PilhaClientes)
		//erro de alocação!
		return 0;
	else
		//alocado com sucesso!
		return 1;
}