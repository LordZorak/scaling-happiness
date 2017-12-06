#ifndef CAIXA_H
#define CAIXA_H

// Assinaturas das funções e structs de caixa.c
typedef struct cliente Cliente;
typedef struct Caixa Caixa;

void definirPilha(int n, int m);
void atenderCliente(Cliente primeiroDaFila);
Cliente desempilharCliente(int CaixaASerDesempilhado);
int limiteDeCaixas(int caixaAtual);
int pilhaEstaCheia(int topoPilha);
int pilhaEstaVazia(int topoPilha);
int getTopo(int posicao);

#endif
