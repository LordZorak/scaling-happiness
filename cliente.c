#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"


//Declaração de uma estrutura de dados paa gerenciar a fila de clientes
typedef struct minhafila{
	Cliente *mFila;
	int f;
	int r;
	int tamanho;
}minhafila;
//definição de variáveis globais
minhafila FilaClientes;
Cliente *teste;

//fç de criar fila. Primeiro aloca e define a frente e a retaguarda como 0. A função retorna 1 se obter sucesso, 0 caso contrário
int definir_fila(int n){
	FilaClientes.tamanho=floor(sqrt(n));
	FilaClientes.mFila = (Cliente *)malloc(FilaClientes.tamanho*sizeof(Cliente));
	FilaClientes.f=0;
	FilaClientes.r=0;
	if(!FilaClientes.mFila){
		return 0;
	}else
		return 1;
}

//fç que insere na fila circular. Em caso de fila cheia, ele remove o primeiro elemento e manda pra pilha de algum caixa;
int inserir_fila(Cliente cliente){
	int posicao = FilaClientes.r % FilaClientes.tamanho+1;
	if(posicao!=FilaClientes.f){
		FilaClientes.r=posicao;
		FilaClientes.mFila[FilaClientes.r-1]=cliente;
		int i;
		printf("\n\n");
		for (i=0;i<FilaClientes.tamanho;i++){
			printf("%d-%d-%d\n",FilaClientes.mFila[i].codigo, FilaClientes.mFila[i].operacao,FilaClientes.mFila[i].valor);
		}
		printf("\n\n");
		if(FilaClientes.f==0){
			FilaClientes.f=1;
		}

	}else{
		printf("overflow\n");
	}
}