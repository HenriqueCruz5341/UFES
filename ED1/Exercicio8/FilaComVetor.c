#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

#define MAX 9

struct FilaComVetor {
    int* items[MAX];
    int ini;
    int tam;
};

Fila* inicializaFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->ini = 0;
    fila->tam = 0;

    return fila;
}

void insereFila(Fila* f, int* num) {
    if (!f || f->tam == MAX) {
        printf("Fila não existe ou está cheia!\n");
        return;
    }

    int pos = (f->ini + f->tam) % MAX;
    f->items[pos] = num;
    f->tam++;
}

void retiraFila(Fila* f) {
    if (!f || f->tam == 0) {
        printf("Fila não existe ou não possui elementos!\n");
        return;
    }

    int pos = (f->ini + 1) % MAX;
    f->ini = pos;
    f->tam--;
}

void imprimeFila(Fila* f) {
    int i;
    int pos;

    if (!f || f->tam == 0) {
        printf("Fila não existe ou não possui elementos!\n");
        return;
    }

    for (i = 0; i < f->tam; i++) {
        pos = (f->ini + i) % MAX;
        printf(" - %d\n", *f->items[pos]);
    }
}

void destroiFila(Fila* f) {
    if (f)
        free(f);
    else
        printf("Fila não existe!\n");
}