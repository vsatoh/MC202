typedef struct {
    char nome[1000];
    float M;
    int N, medidas[1000], media; 
} represa;

represa le_represa(); //le valores da entrada e cria uma variavel do tipo represa

int verif_represa(represa rep); //verifica se a represa esta acima do nivel de seguraça (90%)

void print_represa(represa rep); //imprime as infos das represas de acordo com o modelo do enunciado

void proces_nome_represa(represa rep_vet[], int T); // Modula os nomes das represas

represa rem_rep(represa rep); // remove o prefixo, se houver, represa_de_

represa modula_rep (represa rep); // troca "_" por " ", maiusculas -> minusculas, remove números