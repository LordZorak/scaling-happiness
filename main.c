#include <stdio.h>
#include "cliente.h"
#include "caixa.h"
#include "relatorio.h"

/* Trabalho de Estrutura de Dados e Algoritmos I - MATA40
 * Desenvolvido por Fábio Gomes Lopes e Gustavo Oliveira Quinteiro 
 * Maiores detalhes do desenvolvimento vide https://github.com/LordZorak/scaling-happiness */

// Declaração de variáveis globais
int numeroCaixas, numeroClientes; 

// Função que lê a quantidade de caixas funcionais, e a quantidade de clientes que serão atendidos, no banco
void leituraDadosDeEntrada(){
	int m,n;	
	scanf("%d %d", &m,&n);
	numeroCaixas = m;
	numeroClientes = n;
}

// Função que lê os dados dos clientes
void leituraDeClientes(int numeroClientes){
	int codigo, operacao, valor;
	for(int i = 0; i < numeroClientes; i++){
		scanf("%d %d %d", &codigo, &operacao, &valor);
		criarCliente(codigo, operacao, valor);
	}
}
 
// Main onde executa as funções requisitadas no trabalho, respeitando o conceito de TAD 
int main(){
	
	leituraDadosDeEntrada();
		
	definirFila(numeroClientes);
	
	definirPilha(numeroClientes,numeroCaixas);
	
	leituraDeClientes(numeroClientes);
	
	processaDados();
	
	processarOperacoes(); 
	
	listar(); 
	
	return 0;
}
