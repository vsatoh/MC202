typedef struct visita *p_visita;
typedef struct mapa *p_mapa;

struct visita {
    int data, pista;
    char *nome;
    p_visita esq, dir;
};

struct mapa {
    int visitas;
    char *nome;
    p_mapa esq, dir;
};

p_visita criar_visita();

p_mapa criar_mapa();

p_visita inserir_no_visita(p_visita raiz, int data, char nome[], int pista, int len);

p_mapa inserir_no_mapa(p_mapa raiz, char nome[], int len);

p_visita minimo_visita(p_visita raiz);

p_mapa minimo_mapa(p_mapa raiz);

void remover_mapa(p_mapa raiz);

void remover_visita(p_visita raiz);

p_visita exclui_visita(p_visita visita, int data);

p_mapa exclui_mapa(p_mapa mapa, char nome[]);

p_visita encontra_visita(p_visita visita, int data);

//void excluir(p_mapa mapa, p_visita visita);

void relatorio_pista(p_visita visita);

void relatorio_data(p_visita visita);

//void pre_ordem(p_mapa raiz, char ordem[]);

//void pre_ordem_v(p_visita raiz);

void libera_arvore_visita(p_visita raiz);

void libera_arvore_mapa(p_mapa raiz);