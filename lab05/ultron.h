typedef struct matriz *p_matriz;

struct matriz {
    int **mat;
    int lin;
    int col;
    int lin_aloc;
    int col_aloc;
};

p_matriz cria_mtrx();

void le_mtrx(p_matriz m);

void in_l(p_matriz m);

void out_l(p_matriz m);

void in_c(p_matriz m);

void out_c(p_matriz m);

void ordena_mtrx(p_matriz m, int ind);

void espaco_aloc_linha(p_matriz m);

void espaco_aloc_coluna(p_matriz m);

void realoca_memoria(p_matriz m);

void imprime(p_matriz m);

void destroi(p_matriz m);