typedef struct {
    int p, c;
} casos;

typedef struct {
    casos *v;
    int n, tamanho;
} FP;

typedef FP *p_fp;

p_fp criar_filaprio(int tam);

void insere_caso(casos caso, p_fp fprio);

void troca(casos *a, casos *b);

void sobe_no_heap(p_fp fprio, int k);

void desce_no_heap(p_fp fprio, int k);

casos extrai_minimo(p_fp fprio);

int busca_caso(p_fp fprio, int busca_ind);

void muda_prioridade(p_fp fprio, int k, int valor, int busca_ind);