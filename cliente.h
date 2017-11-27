typedef struct cliente{
	int codigo;
	int operacao;
	int valor;
} Cliente;

typedef struct minhafila minhafila;
//cria a fila
int definir_fila(int n);
//insere na fila
int inserir_fila(Cliente cliente);

//remove primeiro elemento da fila
Cliente remover_fila();

void desinfileirarCliente (minhafila fila, Cliente cliente); 

