#include "PilhaOperador.h"

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 50

struct pilhaOperador {
    char operando[MAXTAM];
    int topo;
};

PilhaOperador* inicializaPilhaOperador() {
    PilhaOperador* p = (PilhaOperador*)malloc(sizeof(PilhaOperador));

    p->topo = -1;

    return p;
}

void pushPilhaOperador(PilhaOperador* p, int num) {
    if (!p || (p->topo) + 1 == MAXTAM) {
        printf("A pilhaOperador não foi inicializada ou estão cheias!!!\n");
        return;
    }

    (p->topo)++;
    p->operando[p->topo] = num;
}

char popPilhaOperador(PilhaOperador* p) {
    int removido = p->operando[p->topo];
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
        printf(" - %d\n", p->operando[aux]);
    }
}

void destroiPilhaOperador(PilhaOperador* p) {
    if (!p) {
        printf("A pilhaOperador não foi inicializada!!!\n");
        return;
    }

    free(p);
}