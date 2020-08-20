#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"
#include "retangulo.h"
#include "triangulo.h"

#define CIR 0
#define RET 1
#define TRI 2

typedef struct celula Celula;

struct celula {
    void* item;
    Celula* prox;
    int tipo;
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

void insereItemLista(Lista* l, void* item, int tipo) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = item;
    nova->tipo = tipo;
    nova->prox = NULL;

    if (l->ult == NULL)
        l->pri = nova;
    else
        l->ult->prox = nova;

    l->ult = nova;
}

void removeItemLista(Lista* l, void* item) {
    Celula* p;
    Celula* ant = NULL;

    for (p = l->pri; p != NULL; p = p->prox) {
        if (p->tipo == CIR) {
            if (retornaIdCirculo(p->item) == retornaIdCirculo(item))
                break;
        } else if (p->tipo == RET) {
            if (retornaIdRetangulo(p->item) == retornaIdRetangulo(item))
                break;
        } else if (p->tipo == TRI) {
            if (retornaIdTriangulo(p->item) == retornaIdTriangulo(item))
                break;
        }
        ant = p;
    }

    if (l->pri == p && l->ult == p) {
        l->pri = NULL;
        l->ult = NULL;
    } else if (l->pri == p) {
        l->pri = p->prox;
    } else if (l->ult == p) {
        l->ult = ant;
        ant->prox = NULL;
    } else {
        ant->prox = p->prox;
    }

    free(p);
}

void imprimeLista(Lista* l) {
    Celula* p;

    for (p = l->pri; p != NULL; p = p->prox) {
        if (p->tipo == CIR)
            imprimeCirculo(p->item);
        if (p->tipo == RET)
            imprimeRetangulo(p->item);
        if (p->tipo == TRI)
            imprimeTriangulo(p->item);
        printf("\n");
    }
}

float calculaAreaTotal(Lista* l) {
    Celula* p;
    float areaTot = 0;

    for (p = l->pri; p != NULL; p = p->prox) {
        if (p->tipo == CIR)
            areaTot += calculaAreaCirculo(p->item);
        else if (p->tipo == RET)
            areaTot += calculaAreaRetangulo(p->item);
        else if (p->tipo == TRI)
            areaTot += calculaAreaTriangulo(p->item);
    }

    return areaTot;
}

void destroiLista(Lista* l) {
    Celula* p = l->pri;
    Celula* prox;

    while (p != NULL) {
        prox = p->prox;
        free(p);
        p = prox;
    }

    free(l);
}