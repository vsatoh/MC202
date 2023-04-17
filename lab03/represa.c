#include <stdio.h>
#include "represa.h"

represa le_represa() {
    int i, aux=0;
    represa rep;
    scanf("%s ", rep.nome);
    scanf("%f", &rep.M);
    scanf("%d", &rep.N);
    for (i = 0; i < rep.N; i++) {
        scanf("%d", &rep.medidas[i]);
        aux += rep.medidas[i];
    }
    rep.media = aux/rep.N;
    return rep;
}

int verif_represa(represa rep) {
    int i;
    float rep_max;
    rep_max = rep.M*0.9;
    for (i = 0; i < rep.N; i++) {
        if(rep.medidas[i] >= rep_max) {
            return 1;
        }
    }
    return 0;
}

void print_represa(represa rep) {
    printf("NOME: %s\n", rep.nome);
    printf("QTD NIVEIS: %d\n", rep.N);
    printf("MEDIA: %d\n", rep.media);
    if (verif_represa(rep) == 1) {
        printf("CAPACIDADE ACIMA DE 90%% DA MAXIMA!\n");
    }
    printf("#####\n");
}

void proces_nome_represa (represa rep_vet[], int T) {
    int i;
    for (i = 0; i < T; i++) {
        rep_vet[i] = rem_rep(rep_vet[i]); // chama a função que remove o prefixo "represa_de_" do nome da represa
        rep_vet[i] = modula_rep(rep_vet[i]); // modula o nome da represa
    }
}

represa rem_rep(represa rep) {
    char rep_pre[11] = "represa_de_";
    int k, j, aux = 1;
    for (k = 0; k < 11; k++) {
        if (rep.nome[k] != rep_pre[k])  {
            aux = 0;
        }  
    }
    if (aux == 1) {
        for (j = 0; rep.nome[j] != '\0'; j++) {
            rep.nome[j] = rep.nome[j + 11];
        }
    }
    return rep;
}

represa modula_rep (represa rep) {
    int j;
    for (j = 0; rep.nome[j] != '\0'; j++) {
        if (65 <= rep.nome[j] && rep.nome[j] <= 90 ) {
            rep.nome[j] += 32;
        }
        else if (rep.nome[j] == '_') {
            rep.nome[j] = ' ';
        }
        else if (48 <= rep.nome[j] && rep.nome[j] <= 57 ) {
            rep.nome[j] = '\0';
        }
    }
    return rep;
}