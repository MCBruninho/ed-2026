#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore minha_arvore = arvore_criar();

    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    printf("Pre-ordem: ");
    arvore_exibir_pre_ordem(minha_arvore);

    printf("Em-ordem: ");
    arvore_exibir_em_ordem(minha_arvore);

    printf("Pos-ordem: ");
    arvore_exibir_pos_ordem(minha_arvore);

    arvore_destruir(minha_arvore);

    return 0;
}