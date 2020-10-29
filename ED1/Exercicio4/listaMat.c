#include "listaMat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula {
    Matriz* matriz;
    Celula* prox;
};

struct lista {
    Celula* pri;
    Celula* ult;
};

Lista* inicializaLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->pri = NULL;
    lista->ult = NULL;

    return lista;
}

void insereInicioLista(Lista* l, Matriz* m) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->matriz = m;
    nova->prox = l->pri;
    l->pri = nova;

    if (l->ult == NULL) l->ult = nova;
}

void insereFimLista(Lista* l, Matriz* m) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->matriz = m;
    nova->prox = NULL;

    if (l->ult == NULL)
        l->pri = nova;
    else
        l->ult->prox = nova;

    l->ult = nova;
}

void imprimeLista(Lista* l) {
    Celula* aux = l->pri;
    int i = 0;

    if (aux == NULL)
        printf("\nLista Vazia!\n");

    while (aux != NULL) {
        printf("\nMatriz: %d\n", i);
        imprimeMatriz(aux->matriz);
        i++;
        aux = aux->prox;
    }
}

Matriz* removeMatrizLista(Lista* l, int index) {
    Celula* aux = l->pri;
    Celula* ant;
    Matriz* mat;
    int i = 0;

    while (aux != NULL && i != index) {
        ant = aux;
        aux = aux->prox;
        i++;
    }

    if (!aux)
        return NULL;

    if (l->pri == l->ult) {
        l->pri = NULL;
        l->ult = NULL;
    } else if (aux == l->pri) {
        l->pri = aux->prox;
    } else if (aux == l->ult) {
        l->ult = ant;
        ant->prox = NULL;
    } else {
        ant->prox = aux->prox;
    }

    mat = aux->matriz;

    free(aux);

    return (mat);
}

void destroiLista(Lista* l) {
    Celula* aux = l->pri;
    Celula* prox;

    if (aux) {
        while (aux) {
            prox = aux->prox;
            free(aux);
            aux = prox;
        }
    }
    free(l);
}