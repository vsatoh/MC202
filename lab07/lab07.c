#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fila.h"
#include "pilha.h"

int ret_num(int len, int n, char linha_in[]);
int comp_exec(char linha_in[]);
int comp_del(char linha_in[]);
void imprime(p_fila fila, p_no no);

int main() {
    int i, len, num;
    char linha_in[500];
    p_fila fila = criar_fila();
    p_pilha pilha = cria_pilha();
    fgets(linha_in,500,stdin);
    empilhar(pilha);
    while(strcmp(linha_in,"EXIT") != 0) {
        len = strcspn(linha_in, "\n");
        if (comp_exec(linha_in) == 1) {
            num = ret_num(len, 4, linha_in);
            for (i = 0; i < num; i++) {
                if(verifica_add(pilha->topo) == 1) {
                    empilhar(pilha);
                }
                adiciona(pilha->topo, desenfileira(fila));
            }
        } else if (comp_del(linha_in) == 1) {
            num = ret_num(len, 3, linha_in);
            for (i = 0; i < num; i++) {
                if(verifica_rmv(pilha->topo) == 1) {
                    desempilhar(pilha);
                }
                retira(pilha->topo);
            }
        } else {
            for (i = 0; i < len; i++) {
                enfileira(fila, linha_in[i]);
            }
        }
        imprime(fila, pilha->topo);
        fgets(linha_in,500,stdin);
    }
    free(fila);
    destroi_pilha(pilha);
    return 0;
}

int ret_num(int len, int n, char linha_in[]) {
    //Converte um número em char para int
    int pot = len - (n + 1), i, num = 0;
    for (i = 0; i < pot; i++){
        num += (linha_in[n + 1 + i] - '0')*pow(10,pot-1-i);
    }
    return num;
}

int comp_exec(char linha_in[]) {
    //verifica se o comando de entrada é o EXEC
    char exec[4] = "EXEC";
    int j, aux = 1;
    for (j = 0; j < 4; j++) {
        if (linha_in[j] != exec[j]) {
            aux = 0;
        }
    }
    return aux;
}

int comp_del(char linha_in[]) {
    //verifica se o comando de entrada é o DEL
    char del[3] = "DEL";
    int j, aux = 1;
    for (j = 0; j < 3; j++) {
        if (linha_in[j] != del[j]) {
            aux = 0;
        }
    }
    return aux;
}

void imprime(p_fila fila, p_no no) {
    //Imprime a pilha e a fila
    printf("FILA ATUAL: ");
    imprime_fila(fila);
    printf("\n");
    printf("PILHA ATUAL: ");
    imprime_pilha(no);
    printf("\n");
    printf("####");
    printf("\n");
}