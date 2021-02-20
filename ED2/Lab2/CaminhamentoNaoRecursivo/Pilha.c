#include "Pilha.h"

#include <stdlib.h>

#include "BST.h"

#define MAXTAM 10000000

struct pilha {
    void* item[MAXTAM];
    int topo;
};

Pilha* inicializaPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

void pushPilha(Pilha* p, void* item) {
    if (!p || (p->topo) + 1 == MAXTAM)
        return;

    (p->topo)++;
    p->item[p->topo] = item;
}

void* popPilha(Pilha* p) {
    if (p->topo < 0)
        return NULL;

    return p->item[p->topo--];
}

void* olharTopoPilha(Pilha* p) {
    return p->item[p->topo];
}

int pilhaVazia(Pilha* p) {
    return p->topo < 0 ? 1 : 0;
}

void destroiPilha(Pilha* p) {
    if (!p) {
        return;
    }

    free(p);
}