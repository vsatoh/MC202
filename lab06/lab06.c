#include <stdio.h>
#include <stdlib.h>
#include "cobra.h"

int main() {
    int x, y;
    char entrada[20];
    p_no prov;
    corpo_cobra cobra;
    p_campo fruta, campo;
    prov = malloc(sizeof(struct no));
    campo = cria_campo();
    prov->x = -1; //valor arbitrário apenas para ter um valor atribuído
    prov->y = -1;
    scanf("%s ", entrada);
    fruta = cria_campo();
    scanf("%s ", entrada);
    scanf("%d", &y);
    scanf("%d", &x);
    cobra = cria_cobra();
    cobra = insere_no(cobra, x, y);
    imprime_campo(campo, cobra, fruta);
    while (verifica_cobra(cobra.cabeca->prox, prov->x, prov->y) != 1 && verifica_vitoria(cobra, campo) != 1) {
        if (verifica_fruta(cobra.cabeca, fruta) == 1) {
            scanf("%s ", entrada);
            free(fruta);
            fruta = cria_campo();
            imprime_campo(campo, cobra, fruta);
        }
        free(prov);
        prov = cmd_cobra(cobra, campo, fruta);
        cobra = verifica(cobra, campo, fruta, prov);
    }
    destruir_cobra(cobra);
    free(campo);
    free(fruta);
    free(prov);
    return 0;
}