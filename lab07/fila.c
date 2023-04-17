#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

p_fila criar_fila() {
    //cria a fila
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->ini = 0;
    f->fim = 0;
    f-> N = 500;
    f->tamanho = 0;
    return f;
}

void enfileira(p_fila f, char c) {
    //enfileira
    f->v[f->fim] = c;
    f->fim = (f->fim + 1)%f->N;
    f->tamanho++;
}

char desenfileira(p_fila f) {
    //desenfileira
    char c = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho--;
    return c;
}

void imprime_fila(p_fila f){
    //imprime a fila
    int i;
    for(i = 0; i < f->tamanho; i++) {
        printf("%c",f->v[(i+f->ini)%f->N]);
    }
}