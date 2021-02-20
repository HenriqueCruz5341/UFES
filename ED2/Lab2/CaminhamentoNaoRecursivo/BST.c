#include "BST.h"

#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

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
/*
1. Visita t.
2. Caminha recursivamente em pre-ordem na sub-arvore da esquerda.
3. Caminha recursivamente em pre-ordem na sub-arvore da direita.
*/
void bstPreOrderTraversal(BST* a) {
    Pilha* pilha = inicializaPilha();
    while (a) {
        // printf("%d, ", a->chave);
        if (a->dir)
            pushPilha(pilha, a->dir);
        if (a->esq)
            a = a->esq;
        else
            a = popPilha(pilha);
    }
    destroiPilha(pilha);
}

/*
1. Caminha recursivamente em ordem na sub-arvore da esquerda.
2. Visita t.
3. Caminha recursivamente em ordem na sub-arvore da direita.
*/
void bstInOrderTraversal(BST* a) {
    Pilha* pilha = inicializaPilha();
    while (a || !pilhaVazia(pilha)) {
        if (a) {
            pushPilha(pilha, a);
            a = a->esq;
        } else {
            a = popPilha(pilha);
            // printf("%d, ", a->chave);
            a = a->dir;
        }
    }
    destroiPilha(pilha);
}

/*
1. Caminha recursivamente em pos-ordem na sub-arvore da esquerda.
2. Caminha recursivamente em pos-ordem na sub-arvore da direita.
3. Visita t.
*/
void bstPosOrderTraversal(BST* a) {
    Pilha* pilha = inicializaPilha();
    BST* topoPilha;
    BST* lastNode = NULL;
    while (a || !pilhaVazia(pilha)) {
        if (a) {
            pushPilha(pilha, a);
            a = a->esq;
        } else {
            topoPilha = olharTopoPilha(pilha);
            if (topoPilha->dir && lastNode != topoPilha->dir)
                a = topoPilha->dir;
            else {
                // printf("%d, ", topoPilha->chave);
                lastNode = popPilha(pilha);
            }
        }
    }
    destroiPilha(pilha);
}

BST* bstLibera(BST* a) {
    if (a) {
        bstLibera(a->esq);
        bstLibera(a->dir);
        free(a);
    }

    return NULL;
}
