#include "PilhaOperador.h"

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 50

struct pilhaOperador {
    char operador[MAXTAM];
    int topo;
};

PilhaOperador* inicializaPilhaOperador() {
    PilhaOperador* p = (PilhaOperador*)malloc(sizeof(PilhaOperador));

    p->topo = -1;

    return p;
}

void pushPilhaOperador(PilhaOperador* p, char op) {
    if (!p || (p->topo) + 1 == MAXTAM) {
        printf("A pilhaOperador não foi inicializada ou estão cheias!!!\n");
        return;
    }

    (p->topo)++;
    p->operador[p->topo] = op;
}

char popPilhaOperador(PilhaOperador* p) {
    char removido = p->operador[p->topo];
    (p->topo)--;

    return removido;
}

void imprimePilhaOperador(PilhaOperador* p) {
    int aux;

    if (!p) {
        printf("A pilhaOperador não foi inicializada!!!\n");
        return;
    }

    for (aux = p->topo; aux >= 0; aux--) {
        printf(" - %c\n", p->operador[aux]);
    }
}

void destroiPilhaOperador(PilhaOperador* p) {
    if (!p) {
        printf("A pilhaOperador não foi inicializada!!!\n");
        return;
    }

    free(p);
}