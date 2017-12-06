#ifndef RELATORIO_H
#define RELATORIO_H

// Assinaturas das funções e structs de relatorio.c
typedef struct cliente Cliente;	
typedef struct relatorio Relatorio;

void processarOperacoes();
Relatorio* alocaNovoElemento(Cliente novoCliente);
void efetuarOperacoes(Relatorio *relatorioFinal, Cliente clienteAtendido);
Relatorio* pesquisaCliente(Cliente clienteAtendido);
void inserirClienteNaLista(Cliente clienteAtendido);
void listar();


#endif
