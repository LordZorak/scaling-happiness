//declaração caixa

typedef struct Caixa{
	Cliente *pilhaClientes;
	int topo;
	int tamanho;
}Caixa;

int definir_pilha(int n, int m);
void atender_cliente (Cliente cliente); 
int PilhaEstaCheia(int topoPilha);
int PilhaEstaVazia(int topoPilha);
