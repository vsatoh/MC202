#include "ultron.h"
#include <stdio.h>
#include <stdlib.h>

p_matriz cria_mtrx() {
    //cria uma variavel do tipo matriz
    int i, lin, col;
    p_matriz m;
    m = malloc(sizeof(struct matriz));
    scanf("%d", &lin);
    scanf("%d", &col);
    m->lin = lin;
    m->col = col;
    m->lin_aloc = lin;
    m->col_aloc = col;
    m->mat = malloc((m->lin)*sizeof(int *));
    for (i = 0; i < m->lin; i++) {
        m->mat[i] = malloc((m->col)*sizeof(int));
    }
    return m;
}

void le_mtrx(p_matriz m) {
    //le uma matriz e guarda na struct
    int i, j, num;
    for (i = 0; i < m->lin; i++) {
        for (j = 0; j < m->col; j++) {
            scanf("%d", &num);
            m->mat[i][j] = num;
        }
    }
}

void in_l(p_matriz m) {
    //insere uma linha apos a aultima linha da matriz
    int l, i;
    espaco_aloc_linha(m);
    for (i = 0; i < m->col; i++) {
        scanf("%d", &l);
        m->mat[m->lin_aloc][i] = l;
    }
    m->lin_aloc++;
}

void out_l(p_matriz m) {
    //remove uma linha e as linhas posteriores sao movidas a fim de completar esse slot vazio
    int ind, i, j;
    espaco_aloc_linha(m);
    scanf("%d", &ind);
    for (i = ind; i < (m->lin_aloc)-1; i++) {
        for (j = 0; j < m->col_aloc; j++) {
            m->mat[i][j] = m->mat[i+1][j];
        }
    }
    m->lin_aloc--;
}

void in_c(p_matriz m) {
    //insere uma coluna mantendo uma ordem crescente
    int i;
    espaco_aloc_coluna(m);
    for (i = 0; i < m->lin_aloc; i++) {
        ordena_mtrx(m, i);
    }
    m->col_aloc++;
}

void out_c(p_matriz m) {
    //remove uma coluna e as colunas posteriores sao movidas a fim de completar esse slot vazio
    int ind, i, j;
    espaco_aloc_coluna(m); 
    scanf("%d", &ind);
    for (i = 0; i < m->lin_aloc; i++) {
        for (j = ind; j < (m->col_aloc)-1; j++) {
            m->mat[i][j] = m->mat[i][j+1];
        }
    }
    m->col_aloc--;
}

void ordena_mtrx(p_matriz m, int ind) {
    //oencontra a posicao que um elemento deve ser inserido em uma linha
    int i, x, pos = 0;
    scanf("%d", &x);
    for(i = 0; i < m->col_aloc; i++) {
        if (x > m->mat[ind][i]) {
            pos = i+1;
        }
    }
    for (i = m->col_aloc; i >= pos; i--) {
        m->mat[ind][i+1] = m->mat[ind][i];
    }
    m->mat[ind][pos] = x;
}

void espaco_aloc_linha(p_matriz m) {
    //verifica o espaco alocado de uma linha
    if (m->lin_aloc == m->lin) {
        m->lin *= 2;
        realoca_memoria(m);
    }
    else if(m->lin_aloc == m->lin/4) {
        m->lin /= 2;
        realoca_memoria(m);
    }
}

void espaco_aloc_coluna(p_matriz m) {
    //verifica o espaco alocado de uma coluna
    if (m->col_aloc == m->col) {
        m->col *= 2;
        realoca_memoria(m);
    }
    else if(m->col_aloc == m->col/4) {
        m->col /= 2; 
        realoca_memoria(m);
    }
}

void realoca_memoria (p_matriz m) {
    //realoca memoria de uma coluna ou linha
    int i, j, **temp;
    temp = m->mat;
    m->mat = malloc((m->lin)*sizeof(int *));
    for (i = 0; i < m->lin; i++) {
        m->mat[i] = malloc((m->col)*sizeof(int));
    }
    for (i = 0; i < m->lin_aloc; i++) {
        for (j = 0; j < m -> col_aloc; j++) {
            m->mat[i][j] = temp[i][j];
        }
        free(temp[i]);
    }
    free(temp); 
}

void imprime(p_matriz m) {
    //imprime uma matriz
    int i, j;
    for (i = 0; i < m->lin_aloc; i++) {
        for (j = 0; j < m->col_aloc; j++) {
            printf("%d ", m->mat[i][j]);
        }
        printf("\n");
    }
    printf("###\n");
}

void destroi(p_matriz m) {
    //destroi uma variavel do tipo matriz
    int i;
    for (i = 0; i < m->lin; i++) {
        free(m->mat[i]);
    }
    free(m->mat);
    free(m);
}