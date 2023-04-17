typedef struct no *p_no;
typedef struct campo *p_campo;


struct no {
    int x, y;
    p_no prox, ant;
};

typedef struct {
    int tamanho;
    p_no cabeca, cauda;
} corpo_cobra;

struct campo {
    int x,y, tamanho;
};

corpo_cobra cria_cobra();

p_campo cria_campo();

void destruir_cobra(corpo_cobra cobra);

void destruir_no(p_no no);

corpo_cobra insere_no(corpo_cobra cobra, int x, int y);

void imprime_campo(p_campo campo, corpo_cobra cobra, p_campo fruta);

int imprime_cobra(p_no ini, p_campo fruta, int x, int y);

p_no cmd_cobra(corpo_cobra cobra, p_campo campo, p_campo fruta);

corpo_cobra verifica(corpo_cobra cobra, p_campo campo, p_campo fruta, p_no prov);

int verifica_cobra(p_no no, int x, int y);

void anda_cobra(p_no cauda, p_no cabeca, p_no prov);

int verifica_fruta(p_no no, p_campo fruta);

int verifica_vitoria(corpo_cobra cobra, p_campo campo);