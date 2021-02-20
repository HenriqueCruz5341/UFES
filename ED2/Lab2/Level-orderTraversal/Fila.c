#include "Fila.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

struct FilaComVetor {
    void* items[MAX];
    int ini;
    int tam;
};

Fila* inicializaFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->ini = 0;
    fila->tam = 0;

    return fila;
}

void insereFila(Fila* f, void* item) {
    if (!f || f->tam == MAX) {
        printf("Fila não existe ou está cheia!\n");
        return;
    }

    int pos = (f->ini + f->tam) % MAX;
    f->items[pos] = item;
    f->tam++;
}

void* retiraFila(Fila* f) {
    if (!f || f->tam == 0) {
        return NULL;
    }

    void* aux = f->items[f->ini];

    int pos = (f->ini + 1) % MAX;
    f->ini = pos;
    f->tam--;

    return aux;
}

void destroiFila(Fila* f) {
    if (f)
        free(f);
    else
        printf("Fila não existe!\n");
}