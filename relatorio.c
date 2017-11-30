#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"
#include "relatorio.h"

typedef struct relatorio{
	Cliente cliente;
	int quantidadeOperacoes;
	int saldoCliente;
}Relatorio;

Relatorio relatoriofinal;
//Pesquisar o cliente a ser recebido 
//Se encontrado atualizar dados de saldo(1 = saque(-) ou 0 = deposito(+)) e contadorOperacoes++
//Senao inserir de modo crescente pelo id e contadorClientesDistintos++


void efetuarOperacoes(Relatorio relatoriofinal){
	if(relatoriofinal.cliente.operacao == 0){
		relatoriofinal.saldoCliente += relatoriofinal.cliente.valor; 
	}else{
		relatoriofinal.saldoCliente -= relatoriofinal.cliente.valor;
	}
	relatoriofinal.quantidadeOperacoes++;
}	


