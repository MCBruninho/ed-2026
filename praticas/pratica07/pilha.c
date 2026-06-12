#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

typedef struct pilha_t {
    no_t* topo;
} pilha_t;

Pilha pilha_criar() {
    Pilha p = (Pilha)malloc(sizeof(pilha_t));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

int pilha_esta_vazia(Pilha p) {
    if (p == NULL) return 1;
    return (p->topo == NULL);
}

int pilha_empilhar(Pilha p, int valor) {
    if (p == NULL) return 0;

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;

    return 1;
}

int pilha_desempilhar(Pilha p) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;

    no_t* no_remover = p->topo;
    p->topo = no_remover->proximo; 
    
    free(no_remover);
    return 1;
}

int pilha_topo(Pilha p, int *valor_topo) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;
    
    *valor_topo = p->topo->valor; 
    return 1;
}

void pilha_exibir(Pilha p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    no_t* atual = p->topo;
    printf("Pilha (Topo -> Base): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void pilha_destruir(Pilha p) {
    if (p == NULL) return;

    no_t* atual = p->topo;
    while (atual != NULL) {
        no_t* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    free(p);
}