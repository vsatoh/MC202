#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int hash(int id,int n_funcao) {
    // funcao de hash
    int n =0;
    n = id%n_funcao;
    return n;
}

p_hash criar_hash(int n_funcao) {
    //cria um variavel do tipo hash
    p_hash novo_hash;
    novo_hash = malloc(sizeof(struct hash));
    novo_hash->vetor = malloc(n_funcao*sizeof(struct no));
    return novo_hash;
}

void inserir(p_hash t, char chave[], int dado, int id, int n, int n_funcao) {
    //insere no hash
    if (t->vetor[n].removido == 1) {
        for (int i = 0; i < 50; i++)
            t->vetor[n].nome_processo[i] = chave[i];
        t->vetor[n].tempo = dado;
        t->vetor[n].id = id;
        t->vetor[n].removido = 0;
    } 
    else {
        inserir(t, chave, dado, id, (n+1)%n_funcao, n_funcao);
    }
}


void consulta_nome (p_hash t,int id, int n,int n_funcao) {
    //consulta o nome do processo
    if (t->vetor[n].removido == 1)  
        printf("PROCESSO %d NAO ENCONTRADO!\n", id);
    else if (t->vetor[n].id == id) {
        printf("PROCESSO %d: %s\n", t->vetor[n].id,t->vetor[n].nome_processo);
    }
    else {
        consulta_nome(t, id, (n+1)%n_funcao, n_funcao);
    }
}

void consulta_tempo (p_hash t,int id, int n,int n_funcao) {
    //consulta o tempo do processo
    if (t->vetor[n].removido == 1) 
        printf("PROCESSO %d NAO ENCONTRADO!\n", id);
    else if (t->vetor[n].id == id) {
        printf("TEMPO DO PROCESSO %d: %d DIAS.\n", t->vetor[n].id,t->vetor[n].tempo);
    }
    else {
        consulta_tempo(t, id, (n+1)%n_funcao, n_funcao);
    }
}

void remove_caso(p_hash t,int id, int n,int n_funcao) {
    //remove o caso
    if (t->vetor[n].id == id) {
        printf("PROCESSO %d REMOVIDO!\n", id);
        t->vetor[n].removido = 1;
    }
    else {
        remove_caso(t , id, (n+1)%n_funcao, n_funcao);
    }
}

void destroi_hash(p_hash t,int n_funcao) {
    //destroi o hash
    free(t->vetor);
    free(t);
}