#include <stdio.h>
#include "fila.h"

int main() {
    Fila minha_fila = fila_criar();

    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    
    fila_exibir(minha_fila);

    int valor_inicio;
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("O valor no inicio eh: %d\n", valor_inicio);
    }

    fila_desenfileirar(minha_fila); 
    fila_exibir(minha_fila);

    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("O novo valor no inicio eh: %d\n", valor_inicio);
    }

    fila_destruir(minha_fila);

    return 0;
}