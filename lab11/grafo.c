#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

p_grafo criar_grafo(int n) {
    // cria um grafo
    int i;
    p_grafo g;
    g = malloc(sizeof(struct grafo));
    g->n = n;
    g->adjacencia = malloc(n*sizeof(p_no));
    for(i = 0; i < n; i++)
        g->adjacencia[i] = NULL;
    return g;        
}

void libera_lista(p_no lista) {
    // libera uma lista
    if (lista != NULL) {
        libera_lista(lista->prox);
        free(lista);
    }
}

void destroi_grafo(p_grafo g) {
    // destroi o grafo
    int i;
    for (i = 0; i < g->n; i++)
        libera_lista(g->adjacencia[i]);
    free(g->adjacencia);
    free(g);
} 

p_no insere_na_lista(p_no lista, int v, char tipo) {
    // insere um novo no na lista
    p_no novo = malloc(sizeof(struct no));
    novo->vlr = v;
    novo->tipo = tipo;
    novo->prox = lista;
    return novo;
}

void insere_aresta(p_grafo g, int u, int v, char tipo1, char tipo2) {
    //insere uma aresta no grafo entre 2 pontos dados
    g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u, tipo1);
    g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v, tipo2);
}

void re_lista(p_grafo g, int no) {
    // adiciona um novo centro de distruibuicao
    p_no *novo_adjacencia, atual;
    int i = 0, vet_int[50], aux, cont, j, n;
    g->n++;
    novo_adjacencia = malloc((g->n)*sizeof(p_no));
    for(i = 0; i < g->n-1; i++)
        novo_adjacencia[i] = g->adjacencia[i];
    g->adjacencia = novo_adjacencia;
    insere_aresta(g, no, g->n-1, 'C', 'P');
    printf("%d ADICIONADO E CONECTADO A",g->n-1);
    i = 0;
    vet_int[i] = no;
    for(atual = g->adjacencia[no]; atual != NULL; atual = atual->prox) {
        if(atual->vlr != g->n-1) {
            i++;
            vet_int[i] = atual->vlr;
            insere_aresta(g, atual->vlr, g->n-1, 'C', 'P');
        }
    }
    cont = i;
    for (i = 0; i < cont; i++) {
        for(j = cont; j > 0; j--) {
            if (vet_int[j] < vet_int[j-1]) {
                aux = vet_int[j];
                vet_int[j] = vet_int[j-1];
                vet_int[j-1] = aux;
            }
        }
    }
    for (i = 0; i <= cont; i++) {
        printf(" %d",vet_int[i]);
    }
    printf("\n");
}

p_no remove_da_lista(p_no lista, int v) {
    // remove um no da lista
    p_no proximo;
    if (lista == NULL)
        return NULL;
    else if (lista->vlr == v) {
        proximo = lista->prox;
        free(lista);
        return proximo;
    } else {
        lista->prox = remove_da_lista(lista->prox, v);
        return lista;
    }
}

void remove_aresta(p_grafo g, int u, int v) {
    // remove uma aresta do grafo
    g->adjacencia[u] = remove_da_lista(g->adjacencia[u], v);
    g->adjacencia[v] = remove_da_lista(g->adjacencia[v], u);
    printf("ARESTA %d -> %d REMOVIDO\n", u, v);
}



int busca_em_largura(p_grafo g, int r, int vert) {
    // realiza a busca de um ponto a partir de outro dado 
    // calcula a distancia entre eles
    int v = -1, cont = 0, ini;
    int *pai = malloc(g->n * sizeof(int));
    int *visitado = malloc(g->n * sizeof(int));
    p_fila f = criar_fila();
    p_no prov_no;
    for (v = 0; v < g->n; v++) {
        pai[v] = -1;
        visitado[v] = 0;
    }
    enfileira(f,r);
    pai[r] = r;
    visitado[r] = 1;
    while(v != vert) {
        v = desenfileira(f);
        for (prov_no = g->adjacencia[v]; prov_no != NULL; prov_no = prov_no->prox) {
            if (!visitado[prov_no->vlr]) {
                visitado[prov_no->vlr] = 1;
                pai[prov_no->vlr] = v;
                enfileira(f, prov_no->vlr);
            }
        }
    }
    ini = vert;
    while(ini != r) {
        ini = pai[ini];
        cont++;
    }
    printf("DISTANCIA %d -> %d = %d\n", r, vert, cont);
    destruir_fila(f);
    free(visitado);
    free(pai);
    return cont;
}


p_fila criar_fila() {
    // cria uma fila
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}


void enfileira(p_fila f, int x) {
    // adiciona um no na fila
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->vlr = x;
    novo->prox = NULL;
    if (f->ini == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}


void destruir_fila(p_fila f) {
    // destroi uma fila
    destruir_lista(f->ini);
    free(f);
}

void destruir_lista(p_no lista) {
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

int desenfileira(p_fila f) {
    // desenfileira o primeiro no da fila e retorna seu valor
    p_no primeiro = f->ini;
    int x = primeiro ->vlr;
    f->ini = f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(primeiro);
    return x;
}
