#include "ultron.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_funcao(p_matriz m);

int main() {
    int i, num_funcoes;
    p_matriz m;
    m = cria_mtrx();
    le_mtrx(m);
    scanf("%d", &num_funcoes);
    for (i = 0; i < num_funcoes; i++) {
        le_funcao(m);
        imprime(m);
    }
    printf("COMBINACAO MATRICIAL FINALIZADA!");
    return 0;
}

void le_funcao(p_matriz m) {
    //le uma funcao e a chama
    char pre[4], pos;
    scanf("%s ", pre); //le o prefixo
    scanf(" %c", &pos); //le o sufixo
    if(strcmp(pre, "IN") == 0) {
        if(pos == 'C') {
            in_c(m);
        } else if (pos == 'L') {
            in_l(m);
        }
    } else if (strcmp(pre, "OUT") == 0) {
        if(pos == 'C') {
            out_c(m);
        } else if (pos == 'L') {
            out_l(m);
        }
    }
}