MAIN = lab07
CC = gcc
CC_FLAGS = -std=c99 -Wall -Werror -Werror=vla -g -lm

all: $(MAIN)

$(MAIN): $(MAIN).o pilha.o fila.o
	$(CC) $(MAIN).o pilha.o fila.o $(CC_FLAGS) -o $(MAIN)

$(MAIN).o: $(MAIN).c pilha.h
	$(CC) $(CC_FLAGS) -c $(MAIN).c

pilha.o: pilha.c pilha.h
	$(CC) $(CC_FLAGS) -c pilha.c

fila.o: fila.c fila.h
	$(CC) $(CC_FLAGS) -c fila.c

clean:
	rm -rf *.o

rmproper: clean
	rm -rf $(MAIN)

.PHONY: testar_tudo
testar_tudo: $(MAIN)
	@set -e ; \
	if [ ! -d testes ] ; then \
		echo "*****************************************************************" ; \
		echo "Crie ou copie o diretório 'testes' para a mesma pasta do Makefile" ; \
		echo "*****************************************************************" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes/*_in.txt ; do \
		saida=$$(echo "$$entrada" | sed -re 's/\_in.txt$$/_ans.txt/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\_in.txt$$/_out.txt/' ) ; \
		./$(MAIN) < "$$entrada" > "$$saida" ; \
		echo ; \
		echo "Testando $$entrada: " ; \
		if diff "$$resposta" "$$saida" ;  then \
			echo "OK" ; \
		else \
			echo "***********************************"; \
			echo "Falhou para $$entrada" ; \
			echo "***********************************"; \
			exit 1; \
		fi ; \
	done
