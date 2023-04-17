#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

p_visita criar_visita() {
    p_visita visita;
    visita = malloc(sizeof(struct visita));
    visita->data = 0;
    visita->esq = NULL;
    visita->dir = NULL;
    visita->nome = NULL;
    return visita;
}

p_mapa criar_mapa() {
    p_mapa mapa;
    mapa = malloc(sizeof(struct mapa));
    mapa->nome = NULL;
    mapa->dir = NULL;
    mapa->esq = NULL;
    return mapa;
}


p_visita inserir_no_visita(p_visita raiz, int data, char nome[], int pista, int len) {
    // insere um novo no na arvore visita
    if (raiz == NULL) {
        p_visita novo;
        int i;
        novo = malloc(sizeof(struct visita));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->data = data;
        novo->nome = malloc((len+1)*sizeof(char));
        for (i = 0; i < len; i++){
            novo->nome[i] = nome[i];
        }
        novo->pista = pista;
        printf("ARVORE: VISITA\n");
        printf("DATA: %d\n", data);
        printf("CIDADE: %s\n", nome);
        printf("INSERIDO COM SUCESSO!\n");
        printf("####\n");
        return novo;
    }
    if (data < raiz->data)
        raiz->esq = inserir_no_visita(raiz->esq, data, nome, pista, len);
    else 
        raiz->dir = inserir_no_visita(raiz->dir, data, nome, pista, len);
    return raiz;
}

p_mapa inserir_no_mapa(p_mapa raiz, char nome[], int len) {
    // insere um novo no na arvore visita
    p_mapa novo;
    if (raiz == NULL) {
        int i;
        novo = malloc(sizeof(struct mapa));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->nome = malloc((len+1)*sizeof(char));
        for (i = 0; i < len; i++){
            novo->nome[i] = nome[i];
        }
        novo->visitas = 1;
        printf("ARVORE: MAPA\n");
        printf("CIDADE: %s\n", nome);
        printf("INSERIDO COM SUCESSO!\n");
        printf("####\n");
        return novo;
    }

    if (strcmp(nome,raiz->nome) < 0) {
        raiz->esq = inserir_no_mapa(raiz->esq, nome, len);
    }
    else if (strcmp(nome,raiz->nome) > 0){
        raiz->dir = inserir_no_mapa(raiz->dir, nome, len);   
    } else
        raiz->visitas++;
    return raiz;
}

void remover_mapa(p_mapa raiz) {
    //remove um no da arvore mapa
    p_mapa min = raiz->dir;
    p_mapa pai = raiz;
    while (min->esq != NULL) {
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;
    raiz->nome = min->nome;
    raiz->visitas = min->visitas;
}

void remover_visita(p_visita raiz) {
    // remove um no da arvore visita
    p_visita min = raiz->dir;
    p_visita pai = raiz;
    while (min->esq != NULL) {
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min){
        pai->esq = min->dir;
    }
    else {
        pai->dir = min->dir;
    }
    raiz->nome = min->nome;
    raiz->data = min->data;
    raiz->pista = min->pista;
}

p_visita exclui_visita(p_visita visita, int data) {
    //encontra e exclui um no da arvore visita, chama a funcao remove_mapa
    if (visita == NULL) {
        return NULL;
    }
    if (data < visita->data){
        visita->esq = exclui_visita(visita->esq, data);
    }
    else if (data > visita->data){
        visita->dir = exclui_visita(visita->dir, data);
    }
    else if (visita->esq == NULL){
        return visita->dir;
    }
    else if (visita->dir == NULL){
        return visita->esq;
    }
    else {
        remover_visita(visita);
    }
    return visita;
}


p_mapa exclui_mapa(p_mapa mapa, char nome[]) {
    //encontra e diminui uma visita de um no, caso o numero de visitas seja 0, remove ess no
    if (mapa == NULL)
        return NULL;
    if (strcmp(nome,mapa->nome) < 0)
        mapa->esq = exclui_mapa(mapa->esq, nome);
    else if (strcmp(nome,mapa->nome) > 0)
        mapa->dir = exclui_mapa(mapa->dir, nome);
    else {
        //imprime o nome da cidade e o numero de visitas restantes
        mapa->visitas--;
        printf("CIDADE: %s\n", mapa->nome);
        printf("QUANTIDADE DE VISITAS RESTANTES: %d\n", mapa->visitas);
        printf("####\n");
        if (mapa->visitas == 0) {
            if (mapa->esq == NULL)
                return mapa->dir;
            else if (mapa->dir == NULL)
                return mapa->esq;
            else
                remover_mapa(mapa);
        }
    }
    return mapa;
}

p_visita encontra_visita(p_visita visita, int data) {
    //busca uma vista na arvore visita
    if (visita == NULL || data == visita->data) {
        return visita;
    }
    else if (data < visita->data) {
        return encontra_visita(visita->esq, data);
    }
    else {
        return encontra_visita(visita->dir, data);
    }
}

void relatorio_pista(p_visita visita) {
    //imprime a data, cidade que possuem pista do mais novo para o mais antigo, de acordo com o "range" de datas na entrada
    p_visita prov_visita;
    int data_inicial, data_final, i;
    scanf("%d", &data_inicial);
    scanf("%d", &data_final);
    printf("--PISTAS--\n");
    for (i = data_final; i >= data_inicial; i--) {
        prov_visita = encontra_visita(visita,i);
        if(prov_visita != NULL && prov_visita->pista == 1) {
            printf("DATA: %d\n", i);
            printf("CIDADE: %s\n", prov_visita->nome);
            printf("####\n");
        }
    }
}

void relatorio_data(p_visita visita) {
    //imprime as visitas de acordo com o "range" da entrada, da mais antiga para a mais nova
    p_visita prov_visita;
    int data_inicial, data_final, i;
    scanf("%d", &data_inicial);
    scanf("%d", &data_final);
    printf("--VISITAS--\n");
    for (i = data_inicial; i <= data_final; i++) {
        prov_visita = encontra_visita(visita,i);
        if (prov_visita != NULL) {
            printf("DATA: %d\n", i);
            printf("CIDADE: %s\n", prov_visita->nome);
            printf("####\n");
        }
    }
}

void libera_arvore_visita(p_visita raiz) {
    // libera a arvore visita
    if(raiz == NULL) 
        return;
    if(raiz->nome != NULL)
        free(raiz->nome);
    libera_arvore_visita(raiz->esq);
    libera_arvore_visita(raiz->dir);
    free(raiz);
}

void libera_arvore_mapa(p_mapa raiz) {
    // libera a arvore mapa
    if(raiz == NULL) 
        return;
    if(raiz->nome != NULL)
    free(raiz->nome);
    libera_arvore_mapa(raiz->esq);
    libera_arvore_mapa(raiz->dir);
    free(raiz);
}