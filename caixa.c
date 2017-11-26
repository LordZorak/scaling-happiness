#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "caixa.h"

Cliente *PilhaClientes;
int definir_pilha(int n, int m){
	PilhaClientes = (Cliente *) malloc(n/m * sizeof(Cliente));
	if(!PilhaClientes)
		//erro de alocação!
		return 0;
	else
		//alocado com sucesso!
		return 1;
}