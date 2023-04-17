#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void remove_caso(p_fp fprio);
void modifica(p_fp fprio);

int main() {
    p_fp fprio;
    casos caso;
    int tam, i, identificador, codigo, Q;
    char cmd;
    scanf("%d", &tam);
    fprio = criar_filaprio(tam);
    for (i = 0; i < tam; i++) {
        scanf("%d", &identificador);
        scanf("%d", &codigo);
        caso.p = identificador;
        caso.c = codigo;
        insere_caso(caso, fprio);
    }
    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
        scanf(" %c", &cmd);
        if(cmd == 'R') {
            remove_caso(fprio);
        }
        else if(cmd == 'M') {
            modifica(fprio);
        }
    }
    printf("FINALIZADO!\n");
    free(fprio->v);
    free(fprio);
}

void remove_caso(p_fp fprio) {
    //remove um elemento
    int k, j;
    casos caso;
    scanf("%d", &k);
    printf("PROCESSOS REMOVIDOS:");
    for(j = 0; j < k; j++) {
        caso = extrai_minimo(fprio);
        printf(" %d",caso.p);
    }
    printf("\n");
}

void modifica(p_fp fprio) {
    //modifica parametros de um caso
    int busca_ind, novo_cod, k;
    scanf("%d", &busca_ind);
    scanf("%d", &novo_cod);
    k = busca_caso(fprio, busca_ind);
    muda_prioridade(fprio, k, novo_cod, busca_ind);
}