#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

int main() {
    int v[TAM];
    int chave;
    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    chave = v[rand() % TAM];

    inicio = clock();
    int pos = linear_search(v, TAM, chave);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Busca Linear:\n");
    printf("Chave: %d | Posicao: %d\n", chave, pos);
    printf("Tempo: %f segundos\n\n", tempo);

    int k = TAM / 2; 

    int v2[TAM];
    for (int i = 0; i < TAM; i++) {
        v2[i] = v[i];
    }

    inicio = clock();
    int resultado = quick_select(v2, 0, TAM - 1, k);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Quick Select:\n");
    printf("%d-esimo menor elemento: %d\n", k, resultado);
    printf("Tempo: %f segundos\n", tempo);

    return 0;
}