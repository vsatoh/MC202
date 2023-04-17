typedef struct pilha *p_pilha;
typedef struct no *p_no;

struct pilha {
    p_no topo;
};

struct no {
    char dado[50];
    int tamanho;
    p_no prox;
};

p_pilha cria_pilha();

void empilhar(p_pilha pilha);

int verifica_add(p_no no);

int verifica_rmv(p_no no);

void adiciona(p_no no, char c);

void retira(p_no no);

void desempilhar(p_pilha pilha);

void imprime_pilha(p_no no);

void destroi_pilha(p_pilha pilha);