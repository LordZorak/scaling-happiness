typedef struct cliente Cliente;	
typedef struct relatorio Relatorio;

void processarOperacoes();
Relatorio * alocaNovoElemento(Cliente cliente);

void efetuarOperacoes(Relatorio * rel, Cliente cliente);

Relatorio * pesquisaCliente(Cliente cliente);

void inserirClienteNaLista(Cliente cliente);

void listar();
