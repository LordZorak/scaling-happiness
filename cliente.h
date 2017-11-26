typedef struct cliente{
	int codigo;
	int operacao;
	int valor;
} Cliente;

//cria a fila
int definir_fila(int n);
//insere na fila
int inserir_fila(Cliente cliente);