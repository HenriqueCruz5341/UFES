#include "ListaCirc.h"

#include <stdlib.h>

typedef struct celula Celula;

struct celula {
    int id;
    Celula* prox;
};

struct listaCirc {
    Celula* ini;
    Celula* fim;
};

ListaCirc* inicializaLista() {
    ListaCirc* lista = (ListaCirc*)malloc(sizeof(ListaCirc));
    lista->ini = NULL;
    lista->fim = NULL;

    return lista;
}

void populaListaCirc(ListaCirc* l, int qtd) {
    Celula* aux = l->ini;
    for (int i = 1; i <= qtd; i++, aux = aux->prox) {
        Celula* nova = (Celula*)malloc(sizeof(Celula));
        aux = nova;
        aux->id = i;

        if (l->ini == NULL)
            l->ini = aux;
        else
            l->fim->prox = aux;

        l->fim = aux;
        aux->prox = l->ini;
    }
}

int removeListaCirc(ListaCirc* l, int pos) {
    Celula* aux = l->ini;
    Celula* ant;
    int i = 0;
    int removido;

    for (i = 1; i < pos; i++) {
        ant = aux;
        aux = aux->prox;
    }

    if (!aux)
        return 0;

    removido = aux->id;

    if (l->ini == l->fim) {
        l->ini = NULL;
        l->fim = NULL;
    } else {
        l->ini = aux->prox;
        l->fim = ant;
        l->fim->prox = l->ini;
    }

    free(aux);
    return removido;
}

int existeLider(ListaCirc* l) {
    if (l->ini == l->fim)
        return 1;

    return 0;
}

void destroiListaCirc(ListaCirc* l) {
    free(l);
}
