#ifndef CAIXA_H
#define CAIXA_H

// Assinaturas das funções e structs de caixa.c
typedef struct cliente Cliente;
typedef struct Caixa Caixa;

void definir_pilha(int n, int m);
void atender_cliente (Cliente cliente); 
Cliente desempilharCliente(int CaixaASerDesempilhado);
int LimiteDeCaixas(int caixaAtual);
int PilhaEstaCheia(int topoPilha);
int PilhaEstaVazia(int topoPilha);
int getTopo(int posicao);

#endif
