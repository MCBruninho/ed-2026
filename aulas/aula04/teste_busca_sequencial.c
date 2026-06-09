#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 10

int main() {
    int vetor[TAMANHO];

    for(int i=0; i < TAMANHO; i++) {
        vetor[i] = rand() % TAMANHO;
        printf("%i, ", vetor[i]);
    }
    printf("\n");

    int valor;
    printf("Entre com um numero para buscar: ");
    scanf("%i", &valor);

    clock_t inicio = clock();
    int achou = busca_sequencial(vetor, TAMANHO, valor);
    clock_t termino = clock();

    float duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;
    printf("A busca pelo valor %i resultou em %i\n", valor, achou);
    printf("Levou %f segundos bara buscar\n");

    return 0;

}