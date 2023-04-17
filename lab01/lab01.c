#include  <stdio.h>

void imprime(int T, int vet_t[]) {
    // Imprime o vetor u
    int j;
    for (j=0; j < T; j++) {
        printf("%d ", vet_t[j]);
    }
    printf("\n");
}

void banner(int B, int T, int vet_t[]) {
    // Le uma array e compara com o vetor u
    // Os elementos de u que n estiverem nessa array seram suvstituidos por 0
    int vet_b[1000], i, j, ctdo = 0;
    for (i=0; i < B; i++) {
        scanf("%d", &vet_b[i]);
    }
    for (i=0; i < T; i++) {
        ctdo = 0;
        for (j = 0; j < B; j++) {
            if (vet_b[j]==vet_t[i]) {
                ctdo = 1;
            } 
        } 
        if (ctdo == 0) {
            vet_t[i] = 0;
        }
    }
}

void mobius(int M, int T, int vet_t[]) {
    //Multiplica os numeros em posicao impar por um numero escolhido
    int i = 1;
    while (i < T) {
        vet_t[i] *= M;
        i += 2;
    }
}

void mov_cicl(int P, int T, int vet_t[]) {
    // Faz com que o elemento da posicao i ocupe a posicao i+1, e o ultimo elemento ocupe a posicao 0
    int i, j, aux;
    for (j = 0; j < P; j++) {
        aux = vet_t[T-1];
        for (i = T-1; i > 0; i--) {
            vet_t[i] = vet_t[i-1];
        }
        vet_t[0] = aux;
    }
}

void ins_vet (int T, int vet_t[]) {
    // Inverter vetor
    int aux[1000], i;
    for (i=0; i < T; i++) {
        aux[i] = vet_t[T-i-1];
    }
    for (i=0; i < T; i++) {
        vet_t[i] = aux[i];
    }
}

int main() {
    int T, B, M, P, n, i, n_op;
    int vet_t[1000];
    scanf("%d",&T);
    for (i=0; i < T; i++) {
        scanf("%d", &vet_t[i]);
    }
    scanf("%d",&n);
    for (i=0; i < n; i++) {
        scanf("%d",&n_op);
        if (n_op==1) {
            scanf("%d", &B);
            banner(B, T, vet_t);
        } else if (n_op==2) {
            scanf("%d", &M);
            mobius(M, T, vet_t);
        } else if (n_op==3) {
            scanf("%d", &P);
            mov_cicl(P, T, vet_t);
        } else {
            ins_vet(T, vet_t);
        }
        imprime(T, vet_t);
    }
    return 0;
}