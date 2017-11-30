# Makefile do Trabalho de Estrutura de Dados e Algoritmos I - MATA40
# Simulação de Agência Bancária
# Equipe: Fábio Gomes Lopes e Gustavo Oliveira Quinteiro
# Maiores detalhes de desenvolvimento, vide: https://github.com/LordZorak/scaling-happiness

all:  cliente.o caixa.o relatorio.o main.o 
	gcc -g cliente.o caixa.o relatorio.o main.o -o AgenciaBancaria -Wall -Wextra -Werror -Wpedantic -lm

cliente.o:
	gcc -g -c cliente.c -Wall -Wextra -Werror -Wpedantic -lm

caixa.o:
	gcc -g -c caixa.c -Wall -Wextra -Werror -Wpedantic -lm

relatorio.o:
	gcc -g -c relatorio.c -Wall -Wextra -Werror -Wpedantic -lm

main.o:
	gcc -g -c main.c -Wall -Wextra -Werror -Wpedantic -lm

clean:
	rm *.o AgenciaBancaria