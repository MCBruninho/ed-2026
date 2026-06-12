#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

#define TAMANHO_PADRAO 11

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

typedef struct hash_t {
    no_t** tabela;
    int tamanho;
} hash_t;

int calcular_hash(int valor, int tamanho) {
    int hash = valor % tamanho;
    return hash < 0 ? hash + tamanho : hash;
}

TabelaHash hash_criar() {
    TabelaHash h = (TabelaHash)malloc(sizeof(hash_t));
    if (h != NULL) {
        h->tamanho = TAMANHO_PADRAO;
        h->tabela = (no_t**)calloc(h->tamanho, sizeof(no_t*));
        if (h->tabela == NULL) {
            free(h);
            return NULL;
        }
    }
    return h;
}

int hash_esta_vazia(TabelaHash h) {
    if (h == NULL) return 1;
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) return 0;
    }
    return 1;
}

int hash_inserir(TabelaHash h, int valor) {
    if (h == NULL) return 0;

    int indice = calcular_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) return 0; 
        atual = atual->proximo;
    }

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;

    return 1;
}

int hash_buscar(TabelaHash h, int valor) {
    if (h == NULL) return 0;

    int indice = calcular_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    }
    return 0;
}

int hash_remover(TabelaHash h, int valor) {
    if (h == NULL) return 0;

    int indice = calcular_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];
    no_t* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    if (anterior == NULL) {
        h->tabela[indice] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

void hash_exibir(TabelaHash h) {
    if (h == NULL) return;

    for (int i = 0; i < h->tamanho; i++) {
        printf("[%2d]: ", i);
        no_t* atual = h->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

void hash_destruir(TabelaHash h) {
    if (h == NULL) return;

    for (int i = 0; i < h->tamanho; i++) {
        no_t* atual = h->tabela[i];
        while (atual != NULL) {
            no_t* aux = atual->proximo;
            free(atual);
            atual = aux;
        }
    }
    free(h->tabela);
    free(h);
}