#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2) 

p_fp criar_filaprio(int tam) {
    //cria uma fila de prioridade
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam*sizeof(casos));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void insere_caso(casos caso, p_fp fprio) {
    //insere um caso na fila de prioridade
    fprio->v[fprio->n] = caso;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}

void troca(casos *a, casos *b) {
    //troca casos
    casos t = *a;
    *a = *b;
    *b = t;
}

void sobe_no_heap(p_fp fprio, int k) {
    //sobe no heap enquanto as condicoes forem satisfeitas
    if (k > 0 && (fprio->v[PAI(k)].c > fprio->v[k].c || (fprio->v[PAI(k)].c == fprio->v[k].c && fprio->v[PAI(k)].p < fprio->v[k].p))) {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

void desce_no_heap(p_fp fprio, int k) {
    //desce no heap enquanto as condicoes forem satisfeitas
    int menor_filho;
    if (F_ESQ(k) < fprio->n) {
        menor_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n && (fprio->v[F_ESQ(k)].c > fprio->v[F_DIR(k)].c || (fprio->v[F_ESQ(k)].c == fprio->v[F_DIR(k)].c && fprio->v[F_ESQ(k)].p < fprio->v[F_DIR(k)].p)))
            menor_filho = F_DIR(k);
        if (fprio->v[k].c > fprio->v[menor_filho].c || (fprio->v[k].c == fprio->v[menor_filho].c && fprio->v[k].p < fprio->v[menor_filho].p)) {
            troca(&fprio->v[k], &fprio->v[menor_filho]);
            desce_no_heap(fprio, menor_filho);
        }
    }
}

casos extrai_minimo(p_fp fprio) {
    //extrai o menor valor do heap
    casos caso = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return caso;
}

int busca_caso(p_fp fprio, int busca_ind) {
    //busca um caso no heap
    int i, k;
    for(i = 0; i < fprio->n; i++) {
        if(fprio->v[i].p == busca_ind) {
            k = i;
        }
    }
    return k;
}

void muda_prioridade(p_fp fprio, int k, int valor, int busca_ind) {
    //muda prioridade de um caso no heap
    if (fprio->v[k].c > valor) {
        fprio->v[k].c = valor;
        sobe_no_heap(fprio, k);
    } else if(fprio->v[k].c < valor){
        fprio->v[k].c = valor;
        desce_no_heap(fprio, k);
    }
}