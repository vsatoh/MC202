#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

p_pilha cria_pilha() {
    //cria a pilha
    p_pilha pilha;
    pilha = malloc(sizeof(struct pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(p_pilha pilha) {
    //empila
    p_no novo = malloc(sizeof(struct no));
    novo->tamanho = 0;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int verifica_add(p_no no) {
    //verifica se o vetor está completo
    if(no->tamanho == 50) {
        return 1;
    }
    return 0;
}

int verifica_rmv(p_no no) {
    //verifica se n ha mais nenhum elemento no vetor
    if(no->tamanho == 0) {
        return 1;
    }
    return 0;
}

void adiciona(p_no no, char c) {
    //adiciona um caractere no vetor
    no->dado[no->tamanho] = c;
    no->tamanho++;
}

void desempilhar(p_pilha pilha) {
    //desempilha
    p_no topo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(topo);
}

void retira(p_no no) {
    //retira um caractere
    no->tamanho--;
}

void imprime_pilha(p_no no) {
    //imprime a pilha
    int i;
    if (no != NULL) {
        imprime_pilha(no->prox);
        for (i = 0; i < no->tamanho; i++) {
            printf("%c", no->dado[i]);
        }
    }
}

void destroi_pilha(p_pilha pilha) {
    //destroi a pilha
    while (pilha->topo != NULL) {
        desempilhar(pilha);
    }
    free(pilha);
}