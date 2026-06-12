#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t* esquerda;
    struct no_t* direita;
} no_t;

typedef struct arvore_t {
    no_t* raiz;
} arvore_t;

Arvore arvore_criar() {
    Arvore a = (Arvore)malloc(sizeof(arvore_t));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

int arvore_esta_vazia(Arvore a) {
    if (a == NULL) return 1;
    return (a->raiz == NULL);
}

no_t* criar_no(int valor) {
    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo != NULL) {
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

no_t* inserir_no(no_t* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_no(raiz->direita, valor);
    }
    return raiz;
}

int arvore_inserir(Arvore a, int valor) {
    if (a == NULL) return 0;
    a->raiz = inserir_no(a->raiz, valor);
    return 1;
}

void exibir_pre(no_t* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        exibir_pre(raiz->esquerda);
        exibir_pre(raiz->direita);
    }
}

void arvore_exibir_pre_ordem(Arvore a) {
    if (a != NULL) exibir_pre(a->raiz);
    printf("\n");
}

void exibir_em(no_t* raiz) {
    if (raiz != NULL) {
        exibir_em(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibir_em(raiz->direita);
    }
}

void arvore_exibir_em_ordem(Arvore a) {
    if (a != NULL) exibir_em(a->raiz);
    printf("\n");
}

void exibir_pos(no_t* raiz) {
    if (raiz != NULL) {
        exibir_pos(raiz->esquerda);
        exibir_pos(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void arvore_exibir_pos_ordem(Arvore a) {
    if (a != NULL) exibir_pos(a->raiz);
    printf("\n");
}

void destruir_nos(no_t* raiz) {
    if (raiz != NULL) {
        destruir_nos(raiz->esquerda);
        destruir_nos(raiz->direita);
        free(raiz);
    }
}

void arvore_destruir(Arvore a) {
    if (a != NULL) {
        destruir_nos(a->raiz);
        free(a);
    }
}