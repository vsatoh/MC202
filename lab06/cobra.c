#include <stdio.h>
#include <stdlib.h>
#include "cobra.h"

corpo_cobra cria_cobra() {
    //cria uma variavel do tipo corpo_cobra
    corpo_cobra cobra;
    cobra.cabeca = NULL;
    cobra.cauda = NULL;
    cobra.tamanho = 0;
    return cobra;
}

p_campo cria_campo() {
    //cria uma variavel do tipo campo
    int x, y;
    p_campo campo;
    scanf("%d", &y);
    scanf("%d", &x);
    campo = malloc(sizeof(struct campo));
    campo->x = x;
    campo->y = y;
    campo->tamanho = x*y;
    return campo;
}

void destruir_cobra(corpo_cobra cobra) {
    //destroi uma variavel do tipo corpo_cobra
    destruir_no(cobra.cabeca);
}

void destruir_no(p_no no) {
    if (no->prox != NULL) {
        destruir_no(no->prox);
    }
    free(no);
}

corpo_cobra insere_no(corpo_cobra cobra, int x, int y) {
    //insere um no na cobra
    p_no novo_no;
    novo_no = malloc(sizeof(struct no));
    novo_no->x = x;
    novo_no->y = y;
    if (cobra.cabeca == NULL) {
        cobra.cabeca = novo_no;
        cobra.cauda = novo_no;
        novo_no->ant = NULL;
    } else {
        novo_no->ant = cobra.cauda;
        cobra.cauda->prox = novo_no;
        cobra.cauda = novo_no;
    }
    novo_no->prox = NULL;
    cobra.tamanho++;
    return cobra;
}

void imprime_campo(p_campo campo, corpo_cobra cobra, p_campo fruta) {
    //imprime o campo com os elementos
    int i, j;
    for (i = 0; i < campo->y; i++) {
        for(j = 0; j < campo->x; j++) {
            imprime_cobra(cobra.cabeca, fruta, j, i);
        }
        printf("\n");
    }
    printf("\n");
}

int imprime_cobra(p_no ini, p_campo fruta, int x, int y) {
    //imprime a cobra
    if((ini->x==x) && (ini->y==y)) {
        printf("# ");
        return 1;
    } else if((x==fruta->x) && (y==fruta->y)) {
        printf("* ");
        return 1;
    } else if(ini->prox != NULL) {
        imprime_cobra(ini->prox, fruta, x, y);
        return 1;
    }
    printf("_ ");
    return 1;
}

p_no cmd_cobra(corpo_cobra cobra, p_campo campo, p_campo fruta) {
    //le os comandos de movimento
    char cmd;
    int x_prov = cobra.cabeca->x, y_prov = cobra.cabeca->y;
    p_no prov;
    prov = malloc(sizeof(struct no));
    scanf(" %c", &cmd);
    if (cmd == 'w') {
        y_prov = (campo->y + cobra.cabeca->y - 1)%campo->y;
    } else if (cmd == 'a'){
        x_prov = (campo->x + cobra.cabeca->x - 1)%campo->x;
    } else if (cmd == 'd'){
        x_prov = (campo->x + cobra.cabeca->x + 1)%campo->x;
    } else if (cmd == 's'){
        y_prov = (campo->y + cobra.cabeca->y + 1)%campo->y;
    }
    prov->x = x_prov;
    prov->y = y_prov;
    return prov;
}

corpo_cobra verifica(corpo_cobra cobra, p_campo campo, p_campo fruta, p_no prov) {
    //faz algumas verificacoes sobre o estado atual do jogo
    int x_cauda, y_cauda;
    if (verifica_fruta(prov, fruta) == 1) {
        x_cauda = cobra.cauda->x;
        y_cauda = cobra.cauda->y;
        cobra = insere_no(cobra, x_cauda, y_cauda);
    }
    if (verifica_cobra(cobra.cabeca->prox, prov->x, prov->y) != 1) {
        anda_cobra(cobra.cauda,cobra.cabeca, prov);
        imprime_campo(campo, cobra, fruta);
    } else {
        imprime_campo(campo, cobra, fruta);
        printf("GAME OVER");
    }
    return cobra;
}

void anda_cobra(p_no cauda, p_no cabeca, p_no prov) {
    //movimenta a cobra
    if (cauda->ant != NULL) {
        cauda->x = cauda->ant->x;
        cauda->y = cauda->ant->y;
        anda_cobra(cauda->ant, cabeca, prov);
    } else {
        cabeca->x = prov->x;
        cabeca->y = prov->y;
    }
}

int verifica_fruta(p_no no, p_campo fruta) {
    //verifica se ha alguma fruta em campo
    if (no->x == fruta->x && no->y == fruta->y) {
        return 1;
    } else {
        return 0;
    }
}

int verifica_vitoria(corpo_cobra cobra, p_campo campo) {
    //verifica se ganho o jogo
    if (cobra.tamanho == campo->tamanho) {
        printf("YOU WIN");
        return 1;
    } else {
        return 0;
    }
}

int verifica_cobra(p_no no, int x, int y) {
    //verifica se a cobra colidirá com alguma parte de seu corpo
    if (no != NULL) {
        if (no->x == x && no->y == y) {
            return 1;
        } else {
            return verifica_cobra(no->prox, x, y);
        }
    } else {
        return 0;
    }
}