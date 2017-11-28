#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"


//m caixas;
//n clientes

int main(){
	int n,m;	
	scanf("%d %d", &m,&n);
	if(!definir_fila(n)){
		printf("erro de memória - Fila!\n");
		exit(1);
	}
	if(!definir_pilha(n,m)){
		printf("erro de memória - Pilha!\n");
		exit(2);
	}

	for(int i=0;i<n;i++){
		Cliente cliente;
		scanf("%d %d %d", &cliente.codigo, &cliente.operacao, &cliente.valor);
		inserir_fila(cliente);
	}
	processa_dados();

	return 0;
}