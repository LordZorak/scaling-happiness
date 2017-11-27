//declaração caixa

typedef struct Caixa{
	Cliente *pilhaClientes;
	int topo;
	int tamanho;
}Caixa;

int definir_pilha(int n, int m);
Cliente atender_cliente (Cliente cliente); 
int estaCheia(int topoPilha);
