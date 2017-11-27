# Makefile do Trabalho de Estrutura de Dados e Algoritmos I
# Simulação de Agência Bancária


all:  cliente.o caixa.o main.o 
	gcc -g cliente.o caixa.o main.o -o AgenciaBancaria -Wall -Wextra -Werror -Wpedantic

cliente.o:
	gcc -Wall -Wextra -Werror -Wpedantic -g -c cliente.c

caixa.o:
	gcc -Wall -Wextra -Werror -Wpedantic -g -c caixa.c

main.o:
	gcc -Wall -Wextra -Werror -Wpedantic -g -c main.c

clean:
	rm *.o AgenciaBancaria