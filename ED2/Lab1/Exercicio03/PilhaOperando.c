#include "PilhaOperando.h"

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 50

struct pilhaOperando {
    double operando[MAXTAM];
    int topo;
};

PilhaOperando* inicializaPilhaOperando() {
    PilhaOperando* p = (PilhaOperando*)malloc(sizeof(PilhaOperando));

    p->topo = -1;

    return p;
}

void pushPilhaOperando(PilhaOperando* p, double num) {
    if (!p || (p->topo) + 1 == MAXTAM) {
        printf("A pilhaOperando não foi inicializada ou estão cheias!!!\n");
        return;
    }

    (p->topo)++;
    p->operando[p->topo] = num;
}

double popPilhaOperando(PilhaOperando* p) {
    double removido = p->operando[p->topo];
    (p->topo)--;

    return removido;
}

void imprimePilhaOperando(PilhaOperando* p) {
    int aux;

    if (!p) {
        printf("A pilhaOperando não foi inicializada!!!\n");
        return;
    }

    for (aux = p->topo; aux >= 0; aux--) {
        printf(" - %lf\n", p->operando[aux]);
    }
}

void destroiPilhaOperando(PilhaOperando* p) {
    if (!p) {
        printf("A pilhaOperando não foi inicializada!!!\n");
        return;
    }

    free(p);
}