# Makefile do Trabalho de Estrutura de Dados e Algoritmos I
# Simulação de Agência Bancária


all:  cliente.o caixa.o main.o 
	gcc -g cliente.o caixa.o main.o -o AgenciaBancaria -Wall -Wextra -Werror -Wpedantic -lm

cliente.o:
	gcc -g -c cliente.c -Wall -Wextra -Werror -Wpedantic -lm

caixa.o:
	gcc -g -c caixa.c -Wall -Wextra -Werror -Wpedantic -lm

main.o:
	gcc -g -c main.c -Wall -Wextra -Werror -Wpedantic -lm

clean:
	rm *.o AgenciaBancaria