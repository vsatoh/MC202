typedef struct fila *p_fila;

struct fila {
    char v[500];
    int ini, fim, N, tamanho;
};

p_fila criar_fila();

void enfileira(p_fila f, char c);

char desenfileira(p_fila f);

void imprime_fila(p_fila f);