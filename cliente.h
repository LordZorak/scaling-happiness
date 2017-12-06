#ifndef CLIENTE_H
#define CLIENTE_H

// Assinaturas das funções e structs de cliente.c
typedef struct minhafila minhafila;
typedef struct cliente Cliente;

void definirFila(int numeroClientes);
int filaEstaVazia();
void criarCliente(int codigo, int operacao, int valor);
int filaEstaCheia();
void inserirFila(Cliente novoCliente);
Cliente removerDaFila();
void processaDados();

#endif
