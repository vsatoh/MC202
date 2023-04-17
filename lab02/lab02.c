#include  <stdio.h>
#include <string.h>

#define MAX 99
#define QTD 2

int scanner();
void mtrx_print(int n, int out, int MAT[][MAX][QTD]);
void mtrx_gen(int n, int MAT[][MAX][QTD]);
int mtrx_trans(int n, int MAT[][MAX][QTD]);
int mtrx_sum (int n, int MAT[][MAX][QTD]);
int mtrx_mt_elm(int n, int MAT[][MAX][QTD]);
int mtrx_mt_mat(int n, int MAT[][MAX][QTD]);
int mtrx_brd (int n, int MAT[][MAX][QTD]);

int main() {
    int n, num_f, count, MAT[MAX][MAX][QTD], mtrx_out; //MAT é um vetor de matrizes, posição 0 corresponde a A e 1 a B
    char inp_fnctn[20];

    scanf("%d", &n);
    mtrx_gen(n, MAT);
    scanf("%d", &num_f);

    for (count = 0; count < num_f; count++) {
        scanf("%s ", inp_fnctn);
        if (strcmp(inp_fnctn, "TRANSPOSTA") == 0) {
            mtrx_out = mtrx_trans(n, MAT);
        } else if (strcmp(inp_fnctn, "SOMA") == 0)
        {
            mtrx_out = mtrx_sum(n, MAT);
        } else if (strcmp(inp_fnctn, "MULTI_ELEM") == 0)
        {
            mtrx_out = mtrx_mt_elm(n, MAT);
        } else if (strcmp(inp_fnctn, "MULTI_MAT") == 0)
        {
            mtrx_out = mtrx_mt_mat(n, MAT);
        } else if (strcmp(inp_fnctn, "BORDAS") == 0)
        {
            mtrx_out = mtrx_brd(n, MAT);
        } 
        mtrx_print(n, mtrx_out, MAT);
    }
    return 0;
}

int scanner() {
    //Devolve a posição da matriz de acordo com a entrada - A ou B
    char M;
    scanf(" %c", &M);
    M = M - 'A'; //Baseado no valor correspondente do caracter na tabela ASCII
    return M;
}

void mtrx_gen(int n, int MAT[][MAX][QTD]) {
    //Gera uma matriz nxn, sendo 3 colunas de 1 e 3 de 0, até completar n
    int i, j, ind, base = 1;

    for (j = 0; j < n; j+=3) {
        for (ind = 0; ind < 3; ind++) {
            for (i = 0; i < n; i++) {
                MAT[i][j+ind][0] = base;
                MAT[i][j+ind][1] = base;
            }
        }
        base = 1 - base;
    }
}

int mtrx_trans(int n, int MAT[][MAX][QTD]) {
    //Calcula a trsposta de uma matriz X e grava em Y
    int mtrx_aux[MAX][MAX], i, j, in, out;

    in = scanner();
    out = scanner();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mtrx_aux[j][i] = MAT[i][j][in];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            MAT[i][j][out] = mtrx_aux[i][j];
        }
    }
    return out;
}

int mtrx_sum(int n, int MAT[][MAX][QTD]) {
    //Soma os elementos de duas matrizes, caso soma > 1 -> soma = 1, e grava em alguma matriz
    int i, j, in1, in2, out;

    in1 = scanner();
    in2 = scanner();
    out = scanner();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((MAT[i][j][in1] + MAT[i][j][in2]) >= 1) {
                MAT[i][j][out] = 1;
            } else {
                MAT[i][j][out] = 0;
            }
        }
    }
    return out;
}

int mtrx_mt_elm(int n, int MAT[][MAX][QTD]) {
    //Multiplica elemento a elemento de duas matrizes e grava em uma matriz
    int i, j, in1, in2, out;

    in1 = scanner();
    in2 = scanner();
    out = scanner();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            MAT[i][j][out] = MAT[i][j][in1]*MAT[i][j][in2];
        }
    }
    return out;
}

int mtrx_mt_mat(int n, int MAT[][MAX][QTD]) {
    //Realiza a multiplicação matricial de 2 matrizes e grava em uma matriz
    int i, j, k, aux = 0, in1, in2, out;

    in1 = scanner();
    in2 = scanner();
    out = scanner();

    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            aux = 0;
            for (j = 0; j < n; j++) {
                aux += (MAT[i][j][in1]*MAT[j][k][in2]);
            }
            if (aux > 1) {
                aux = 1;
            }
            MAT[i][k][out] = aux;
        }
    }
    return out;
}

int mtrx_brd (int n, int MAT[][MAX][QTD]){
    //Analisa os elementos vizinhos de uma matriz, caso todos sejam iguais a 1, o elemento assume o valor 0
    int mtrx_aux[MAX][MAX], i, j, in, out, i_aux, j_aux, aux = 1;

    in = scanner();
    out = scanner();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            MAT[i][j][out] = MAT[i][j][in];
            mtrx_aux[i][j] = MAT[i][j][in];
        }
    }    
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            aux = 1;
            for (i_aux = -1; i_aux < 2 ; i_aux++) {
                for (j_aux = -1; j_aux < 2 ; j_aux++) {
                    if (mtrx_aux[i + i_aux][j + j_aux] == 0) {
                        aux = 0;
                    }
                }
            }
            if (aux == 1) {
                MAT[i][j][out] = 0;
            }
        }
    }
    return out;
}

void mtrx_print(int n, int out, int MAT[][MAX][QTD]) {
    //Imprime uma matriz
    int i, j;

    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", MAT[i][j][out]);
        }
        printf("\n");
    }
}