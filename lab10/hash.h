#define MAX 2000

typedef struct hash * p_hash;

struct no {
    char nome_processo[50];
    int tempo;
    int id;
    int removido;
};

struct hash {
    struct no *vetor;
};

int hash(int id, int n_funcao);

p_hash criar_hash(int n_funcao);

void inserir(p_hash t, char *chave, int dado, int id, int n,int n_funcao);

void consulta_nome (p_hash t,int id, int n,int n_funcao);

void consulta_tempo (p_hash t,int id, int n,int n_funcao);

void remove_caso(p_hash t,int id, int n,int n_funcao);

void destroi_hash(p_hash t,int n_funcao);