#include "BST.h"

#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct bst {
    int chave;
    BST* esq;
    BST* dir;
};

BST* bstCria(void) {
    return NULL;
}

void bstImprime(BST* a) {
    if (a) {
        bstImprime(a->esq);
        printf("%d, ", a->chave);
        bstImprime(a->dir);
    }
}

BST* bstBusca(BST* a, int chave) {
    return NULL;
}

BST* bstInsere(BST* a, int chave) {
    if (!a) {
        a = (BST*)malloc(sizeof(BST));
        a->chave = chave;
        a->esq = a->dir = NULL;
    } else if (a->chave > chave)
        a->esq = bstInsere(a->esq, chave);
    else if (a->chave < chave)
        a->dir = bstInsere(a->dir, chave);

    return a;
}

BST* bstRetira(BST* a, int chave) {
    return NULL;
}

int bstAltura(BST* a) {
    if (a) {
        int alturaE = bstAltura(a->esq);
        int alturaD = bstAltura(a->dir);
        return 1 + ((alturaE > alturaD) ? alturaE : alturaD);
    }

    return -1;
}

void bstLevelOrderTraversal(BST* a) {
    Fila* fila = inicializaFila();

    while (a) {
        printf("%d, ", a->chave);
        if (a->esq)
            insereFila(fila, a->esq);
        if (a->dir)
            insereFila(fila, a->dir);
        a = retiraFila(fila);
    }

    destroiFila(fila);
}

BST* bstLibera(BST* a) {
    if (a) {
        bstLibera(a->esq);
        bstLibera(a->dir);
        free(a);
    }

    return NULL;
}
