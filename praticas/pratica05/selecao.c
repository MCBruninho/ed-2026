#include "selecao.h"

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int *v, int esquerda, int direita) {
    int pivo = v[direita];
    int i = esquerda;

    for (int j = esquerda; j < direita; j++) {
        if (v[j] <= pivo) {
            troca(&v[i], &v[j]);
            i++;
        }
    }
    troca(&v[i], &v[direita]);
    return i;
}

int quick_select(int *v, int esquerda, int direita, int k) {
    if (esquerda == direita)
        return v[esquerda];

    int pivo = particiona(v, esquerda, direita);

    if (k == pivo)
        return v[k];
    else if (k < pivo)
        return quick_select(v, esquerda, pivo - 1, k);
    else
        return quick_select(v, pivo + 1, direita, k);
}

int linear_search(int *v, int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (v[i] == chave)
            return i;
    }
    return -1;
}