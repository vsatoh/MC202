typedef struct no *p_no;
typedef struct grafo *p_grafo; 
typedef struct fila *p_fila;

struct fila {
    p_no ini, fim;
};

struct no {
    int vlr;
    char tipo;
    p_no prox;
};

struct grafo {
    p_no *adjacencia;
    int n;
};

p_grafo criar_grafo(int n);

void libera_lista(p_no lista);

void destroi_grafo(p_grafo g);

p_no insere_na_lista(p_no lista, int v, char tipo);

void insere_aresta(p_grafo g, int u, int v, char tipo1, char tipo2);

void re_lista(p_grafo g, int no);

p_no remove_da_lista(p_no lista, int v);

void remove_aresta(p_grafo g, int u, int v);

int busca_em_largura(p_grafo g, int r, int vert);

p_fila criar_fila();

void enfileira(p_fila f, int x);

void destruir_fila(p_fila f);

void destruir_lista(p_no lista);

int desenfileira(p_fila f);