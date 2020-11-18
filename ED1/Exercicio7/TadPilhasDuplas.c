#include "TadPilhasDuplas.h"

#include <stdio.h>
#include <stdlib.h>

#define MaxTam 9

typedef int TipoItem;

typedef struct {
    int topo;
    int base;
} IndicePilha;

struct pilhasDuplas {
    TipoItem* item[MaxTam];
    IndicePilha pilha1;
    IndicePilha pilha2;
};

PilhasDuplas* inicializaPilhas() {
    PilhasDuplas* pd = (PilhasDuplas*)malloc(sizeof(PilhasDuplas));

    pd->pilha1.base = 0;
    pd->pilha1.topo = -1;
    pd->pilha2.base = MaxTam - 1;
    pd->pilha2.topo = MaxTam;

    return pd;
}

void pushPilha1(PilhasDuplas* pd, int* num) {
    if (!pd || (pd->pilha1.topo) + 1 == pd->pilha2.topo) {
        printf("As pilhas não foram inicializadas ou estão cheias!!!\n");
        return;
    }

    (pd->pilha1.topo)++;
    pd->item[pd->pilha1.topo] = num;
}

void pushPilha2(PilhasDuplas* pd, int* num) {
    if (!pd || (pd->pilha1.topo) + 1 == pd->pilha2.topo) {
        printf("As pilhas não foram inicializadas ou estão cheias!!!\n");
        return;
    }

    (pd->pilha2.topo)--;
    pd->item[pd->pilha2.topo] = num;
}

int* popPilha1(PilhasDuplas* pd) {
    if (!pd || (pd->pilha1.topo) < 0) {
        printf("As pilhas não foram inicializadas ou a pilha1 está vazia!!!\n");
        return NULL;
    }

    TipoItem* removido = pd->item[pd->pilha1.topo];
    (pd->pilha1.topo)--;

    return removido;
}

int* popPilha2(PilhasDuplas* pd) {
    if (!pd || (pd->pilha2.topo) == MaxTam) {
        printf("As pilhas não foram inicializadas ou a pilha2 está vazia!!!\n");
        return NULL;
    }

    TipoItem* removido = pd->item[pd->pilha2.topo];
    (pd->pilha2.topo)++;

    return removido;
}

void imprimePilha1(PilhasDuplas* pd) {
    int aux;

    if (!pd) {
        printf("As pilhas não foram inicializadas!!!\n");
        return;
    }

    for (aux = pd->pilha1.topo; aux >= 0; aux--) {
        printf(" - %d\n", *(pd->item[aux]));
    }
}

void imprimePilha2(PilhasDuplas* pd) {
    int aux;

    if (!pd) {
        printf("As pilhas não foram inicializadas!!!\n");
        return;
    }

    for (aux = pd->pilha2.topo; aux < MaxTam; aux++) {
        printf(" - %d\n", *(pd->item[aux]));
    }
}

void destroiPilhas(PilhasDuplas* pd) {
    if (!pd) {
        printf("As pilhas não foram inicializadas!!!\n");
        return;
    }

    free(pd);
}