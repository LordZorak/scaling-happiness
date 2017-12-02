#ifndef CLIENTE_H
#define CLIENTE_H

// Assinaturas das funções e structs de cliente.c
typedef struct minhafila minhafila;
typedef struct cliente Cliente;

void definir_fila(int n);
int fila_vazia();
void criarCliente(int codigo, int operacao, int valor);
int FilaCheia();
void inserir_fila(Cliente cliente);
Cliente remover_fila();
void processa_dados();



#endif
