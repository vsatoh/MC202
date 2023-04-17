#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    int c, p, n_aresta, i, n_cmd;
    int u, v;
    int dist_esp = 1, dist_real = 1;
    int r, vert;
    char cmd;
    p_grafo grafo;
    scanf("%d", &c);
    scanf("%d", &p);
    scanf("%d", &n_aresta);
    grafo = criar_grafo(p+c);
    for (i = 0; i < n_aresta; i++) {
        scanf("%d", &u);
        scanf("%d", &v);
        if(u == c+p-1) {
            insere_aresta(grafo, u, v, 'C', 'P');
        } else if(v == c+p-1) {
            insere_aresta(grafo, u, v, 'P', 'C');
        } else
            insere_aresta(grafo, u, v, 'P', 'P');
    }
    printf("GRAFO AMZ CONSTRUIDO!\n");
    scanf("%d", &n_cmd);
    for (i = 0; i < n_cmd; i++) {
        scanf(" %c", &cmd);
        if(cmd == 'D') {
            scanf("%d", &r);
            scanf("%d", &vert);
            dist_real = busca_em_largura(grafo, r, vert);
            scanf("%d", &dist_esp);
            if (dist_real > dist_esp) {
                re_lista(grafo, vert);
            }
        } else if(cmd == 'R') {
            scanf("%d", &r);
            scanf("%d", &vert);
            remove_aresta(grafo, r, vert);
        }
    }
    destroi_grafo(grafo);
}