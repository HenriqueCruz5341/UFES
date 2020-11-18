#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

#define MAX 9

typedef struct celula Celula;

struct celula {
    int* item;
    Celula* prox;
};

struct FilaComLista {
    Celula* ini;
    Celula* fim;
};

Fila* inicializaFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->ini = NULL;
    fila->fim = NULL;

    return fila;
}

void insereFila(Fila* f, int* num) {
    if (!f) {
        printf("Fila não existe!\n");
        return;
    }

    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->item = num;
    nova->prox = NULL;

    if (!f->fim)
        f->ini = nova;
    else
        f->fim->prox = nova;

    f->fim = nova;
}

void retiraFila(Fila* f) {
    if (!f) {
        printf("Fila não existe!\n");
        return;
    }

    if (!f->ini) {
        printf("Fila vazia!\n");
        return;
    }

    Celula* aux = f->ini;

    if (f->ini == f->fim) {
        f->ini = NULL;
        f->fim = NULL;
    } else
        f->ini = aux->prox;

    free(aux);
}

void imprimeFila(Fila* f) {
    if (!f) {
        printf("Fila não existe!\n");
        return;
    }

    if (!f->ini) {
        printf("Fila vazia!\n");
        return;
    }

    Celula* aux;

    for (aux = f->ini; aux; aux = aux->prox) {
        printf(" - %d\n", *aux->item);
    }
}

void destroiFila(Fila* f) {
    if (f) {
        Celula* aux = f->ini;
        Celula* prox;

        while (aux) {
            prox = aux->prox;
            free(aux);
            aux = prox;
        }

        free(f);
    } else
        printf("Fila não existe!\n");
}