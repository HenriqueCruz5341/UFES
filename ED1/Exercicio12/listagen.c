#include "listagen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listagen {
    void *item;
    ListaGen *prox;
};

ListaGen *criaLista() {
    return NULL;
}

ListaGen *insereLista(ListaGen *lista, void *item) {
    ListaGen *nova = (ListaGen *)malloc(sizeof(ListaGen));
    nova->item = item;
    nova->prox = lista;

    return nova;
}
ListaGen *retiraLista(ListaGen *lista, int (*cb)(void *, void *), void *chave) {
    ListaGen *p = lista;
    ListaGen *ant = NULL;

    while (p != NULL && cb(p->item, chave)) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        return lista;
    }

    if (ant == NULL) {
        lista = lista->prox;
    } else {
        ant->prox = p->prox;
    }

    free(p);
    return lista;
}

int percorreLista(ListaGen *lista, int (*cb)(void *, void *), void *dado) {
    ListaGen *p;

    for (p = lista; p != NULL; p = p->prox) {
        int r = cb(p->item, dado);
        if (r == 0) {
            return r;
        }
    }
    return 1;
}
void liberaLista(ListaGen *lista) {
    ListaGen *p = lista;
    ListaGen *t;

    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}