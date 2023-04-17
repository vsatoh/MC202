#include <stdio.h>
#include <stdlib.h>

int *sub_forte (int *v, int n, int *sz_forte, int ind);
int *sub_elite (int **forte, int Q, int *sz_forte);
void imprime_tropa_forte (int *tropa, int sz, int ind);

int main() {
    int Q, n, i, j, *v, **forte, *elite, *sz_forte;
    //forte - armazena as subtropas fortes / elite - armazena a subtropa de elite / sz_forte - armazena o tamanho de cada sub forte
    scanf("%d", &Q);
    forte = malloc((Q)*sizeof(int *));
    sz_forte = malloc((Q+1)*sizeof(int));
    for (i = 0; i < Q; i++) {
        scanf("%d", &n);
        v = malloc(n*sizeof(int));
        for (j = 0; j < n; j++) {
            scanf("%d", &v[j]);
        }
        forte[i] = sub_forte(v, n, sz_forte, i);
        imprime_tropa_forte (forte[i], sz_forte[i], i);
        free(v);
    }
    //Nao separei a impressao da sub de elite em uma função pois seria chamada apenas uma vez
    printf("Sub-tropa Elite: ");
    elite = sub_elite(forte, Q, sz_forte);
    for (j = 0; j < sz_forte[Q]; j++) {
        printf("%d ", elite[j]);
    }

    for (j = 0; j < Q; j++) {
        free(forte[j]);
    }
    free(sz_forte);
    free(forte);
    free(elite);
    return 0;
}

int *sub_forte (int *v, int n, int *sz_forte, int ind) { 
    //Calcula a subtropa mais forte de uma dada tropa
    int i, j, inicio = 0, fim = 0, aux = 0, max = 0, *sub_forte;
    for (i = 0; i < n; i++) {
        aux = v[i];
        if (i == 0 && v[i] < 0) {
            max = v[i];
            inicio = 0;
            fim = 1;
        }
        for (j = i+1; j <= n; j++) {
            if (aux > max) {
                max = aux;
                inicio = i;
                fim = j;
            }
            aux += v[j];
        }
    }
    sub_forte = malloc((fim - inicio)*sizeof(int));
    sz_forte[ind] = fim - inicio;
    j = 0;

    for (i = inicio; i < fim; i++) {
        sub_forte[j] = v[i];
        j++;
    }
    return sub_forte;
}

int *sub_elite (int **forte, int Q, int *sz_forte) {
    //Concatena todas subtropas fortes
    //Normaliza com a média
    //Calcula a subtropa mais forte a partir dessa tropa normalizada
    int i, j, k = 0, media = 0, *total, *sub_elite;
    for (i = 0; i < Q; i++) {
        for (j = 0; j < sz_forte[i]; j++) {;
            media += forte[i][j];
            k++;
        }
    }
    total = malloc(k*sizeof(int));
    k = 0;
    for (i = 0; i < Q; i++) {
        for (j = 0; j < sz_forte[i]; j++) {
            total[k] = forte[i][j];
            k++;
        }
    }
    media = media/k;
    for (i = 0; i < k; i++) {
        total[i] -= media;
    }
    sub_elite = sub_forte(total, k, sz_forte, Q);

    for (i = 0; i < sz_forte[Q]; i++) {
        sub_elite[i] += media; 
    }
    free(total);
    return sub_elite;
}

void imprime_tropa_forte (int *tropa, int sz, int ind) {
    //Imprime a subtropa mais forte
    int j;
    printf("Sub-tropa Forte %d: ", ind+1);
    for (j = 0; j < sz; j++) {
        printf("%d ", tropa[j]);
    }
    printf("\n");
}