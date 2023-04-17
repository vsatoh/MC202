#include <stdio.h>
#include "represa.h"

int main() {
    int T, i;
    represa represas_lst[1000]; //array em que as represas da entrada serao guardadas
    scanf("%d", &T);
    for(i = 0; i < T; i++) {
        represas_lst[i] = le_represa(); // le as represas no input
    }
    proces_nome_represa (represas_lst, T); // pre-processamento dos nomes das represas
    for(i = 0; i < T; i++) {
        print_represa(represas_lst[i]); // imprime as represas
    }    
}