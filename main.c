#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"
#include "relatorio.h"

/* Trabalho de Estrutura de Dados e Algoritmos I - MATA40
 * Desenvolvido por Fábio Gomes Lopes e Gustavo Oliveira Quinteiro 
 * Para maiores detalhes do desenvolvimento vide https://github.com/LordZorak/scaling-happiness */
 
 /* Função main onde se tem a declaração de variáveis correspondentes ao número de clientes, ao número de caixas 
  * e as informações necessárias de um cliente para ser atendido e suas respectivas leituras,
  * além da execução do requisitado no trabalho, em formato de funções, respeitando o conceito de TAD */
int main(){
	int n,m;	
	scanf("%d %d", &m,&n);
	definir_fila(n);
	definir_pilha(n,m);
	int codigo, operacao, valor;
	for(int i=0;i<n;i++){
		scanf("%d %d %d", &codigo, &operacao, &valor);
		criarCliente(codigo, operacao, valor);
	}
	processa_dados();
	
	processarOperacoes(); 
	listar(); 

	return 0;
}
