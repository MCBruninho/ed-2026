#include "selecao.h"

int busca_sequencial(int v[], int n, int valor) {
    for(int i = 0; i < 10; i++) {
        if (v[i] == valor) {
            return i+1;
        }
    }
    return -1;
}