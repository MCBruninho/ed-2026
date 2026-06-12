#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash minha_hash = hash_criar();

    hash_inserir(minha_hash, 15);
    hash_inserir(minha_hash, 26);
    hash_inserir(minha_hash, 37);
    hash_inserir(minha_hash, 42);
    hash_inserir(minha_hash, 53);
    hash_inserir(minha_hash, 64);
    hash_inserir(minha_hash, 10);
    hash_inserir(minha_hash, 21);

    printf("Tabela Hash apos insercoes:\n");
    hash_exibir(minha_hash);

    printf("\nBusca pelo valor 42: %d\n", hash_buscar(minha_hash, 42));
    printf("Busca pelo valor 99: %d\n", hash_buscar(minha_hash, 99));

    printf("\nRemovendo o valor 42...\n");
    hash_remover(minha_hash, 42);
    
    printf("\nTabela Hash apos remocao:\n");
    hash_exibir(minha_hash);

    hash_destruir(minha_hash);

    return 0;
}