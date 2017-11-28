# Makefile do Trabalho de Estrutura de Dados e Algoritmos I
# Simulação de Agência Bancária


all:  cliente.o caixa.o main.o 
	gcc -g cliente.o caixa.o main.o -o AgenciaBancaria -Wall -Wextra -Werror -Wpedantic -lm

cliente.o:
	gcc -Wall -Wextra -Werror -Wpedantic -g -c cliente.c -lm

caixa.o:
	gcc -Wall -Wextra -Werror -Wpedantic -g -c caixa.c -lm

main.o:
	gcc -Wall -Wextra -Werror -Wpedantic -g -c main.c -lm

clean:
	rm *.o AgenciaBancaria