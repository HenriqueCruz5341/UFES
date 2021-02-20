#include "Pilha.h"

#include <stdlib.h>

#define MAXTAM 50

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
    (p->topo)--;

    return p->item[p->topo];
}

void destroiPilha(Pilha* p) {
    if (!p) {
        return;
    }

    free(p);
}