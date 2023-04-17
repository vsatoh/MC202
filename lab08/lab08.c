#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

int main() {
    p_mapa mapa;
    p_visita visita;
    p_visita prov_visita;
    int N, i, data, pista, len;
    char funcao[30], nome[50];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s ", funcao);
        if(strcmp(funcao,"insere_visita") == 0) {
            scanf("%s ", nome);
            scanf("%d", &data);
            scanf("%d", &pista);
            len = strcspn(nome, "\0");
            mapa = inserir_no_mapa(mapa, nome, len);
            visita = inserir_no_visita(visita, data, nome, pista, len);
        } else if(strcmp(funcao,"exclui_visita") == 0) {
            scanf("%d", &data);
            prov_visita = encontra_visita(visita, data);
            mapa = exclui_mapa(mapa, prov_visita->nome);
            visita = exclui_visita(visita, data);
        } else if(strcmp(funcao,"relatorio_data") == 0) {
            relatorio_data(visita);
        } else if(strcmp(funcao,"relatorio_pista") == 0) {
            relatorio_pista(visita);
        }
    }
    free(prov_visita->nome);
    free(prov_visita);
    libera_arvore_mapa(mapa);
    libera_arvore_visita(visita);
}