#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"
#include "relatorio.h"

/* Trabalho de Estrutura de Dados e Algoritmos I - MATA40
 * Desenvolvido por Fábio Gomes Lopes e Gustavo Oliveira Quinteiro 
 * Maiores detalhes do desenvolvimento vide https://github.com/LordZorak/scaling-happiness */

// Função que lê os dados dos N clientes
void leituraDeClientes(int n){
	int codigo, operacao, valor;
	for(int i = 0; i<n; i++){
		scanf("%d %d %d", &codigo, &operacao, &valor);
		criarCliente(codigo, operacao, valor);
	}
}
 
 /* Main onde se tem a leitura da quantidade de clientes e quantidade de caixas 
  * além da execução das funções requisitadas no trabalho, respeitando o conceito de TAD */
int main(){
	
	int n,m;	
	scanf("%d %d", &m,&n);
	
	definirFila(n);
	
	definirPilha(n,m);
	
	leituraDeClientes(n);
	
	processaDados();
	
	processarOperacoes(); 
	
	listar(); 
	
	return 0;
}
