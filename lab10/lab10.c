#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
    int n_funcao, i, id, n, tempo, j;
    char funcao, nome_processo[50];
    p_hash t;
    scanf("%d", &n_funcao);
    t = criar_hash(n_funcao);
    for (j = 0; j < n_funcao; j++)
        t->vetor[j].removido = 1;
    for (i = 0; i < n_funcao; i++) {
        scanf(" %c", &funcao);
        scanf("%d", &id);
        n = hash(id, n_funcao);
        if(funcao == 'I') {
            scanf("%s ", nome_processo);
            scanf("%d", &tempo);
            inserir(t, nome_processo, tempo, id, n, n_funcao);
            printf("PROCESSO %d INSERIDO!\n", id);
        }
        else if(funcao == 'R') {
            remove_caso(t, id, n, n_funcao);
        }
        else if(funcao == 'C') {
            consulta_nome (t, id, n, n_funcao);
        }
        else if(funcao == 'T') {
            consulta_tempo (t, id, n, n_funcao);
        }
    }
    printf("FINALIZADO!");
    destroi_hash(t, n_funcao);
}