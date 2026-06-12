#include <stdio.h>
#include "lista_linear.h"

int main() {
    Lista minha_lista = lista_criar();
    printf("Lista criada com sucesso!\n");

    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_exibir(minha_lista);

    int valor_busca = 20;
    if (lista_buscar(minha_lista, valor_busca)) {
        printf("O valor %d foi encontrado na lista.\n", valor_busca);
    } else {
        printf("O valor %d NAO foi encontrado.\n", valor_busca);
    }

    printf("Removendo o valor 20...\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);

    lista_destruir(minha_lista);
    printf("Lista destruida da memoria.\n");

    return 0;
}