#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha minha_pilha = pilha_criar();
    printf("--- Pilha Criada ---\n");

    // 1. Testando empilhamento (Push)
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_exibir(minha_pilha);

    // 2. Consulta do topo (Peek)
    int valor_do_topo;
    if (pilha_topo(minha_pilha, &valor_do_topo)) {
        printf("\nO valor atual no topo eh: %d\n", valor_do_topo);
    }

    printf("\nDesempilhando o elemento do topo...\n");
    pilha_desempilhar(minha_pilha);
    pilha_exibir(minha_pilha);

    if (pilha_topo(minha_pilha, &valor_do_topo)) {
        printf("\nO novo valor no topo eh: %d\n", valor_do_topo);
    }

    pilha_destruir(minha_pilha);
    printf("\nPilha destruida com sucesso!\n");

    return 0;
}