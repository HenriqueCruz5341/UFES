#include "listaEdi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula {
    Editor* editor;
    Celula* prox;
};

struct listaEdi {
    Celula* ini;
    Celula* fim;
};

ListaEdi* inicializaListaEditor() {
    ListaEdi* listaEdi = (ListaEdi*)malloc(sizeof(ListaEdi));

    listaEdi->ini = NULL;
    listaEdi->fim = NULL;

    return listaEdi;
}

void insereEditor(ListaEdi* l, Editor* e) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->editor = e;
    nova->prox = NULL;

    if (!l->ini)
        l->ini = nova;
    else
        l->fim->prox = nova;

    l->fim = nova;
}

Editor* buscaEditor(ListaEdi* l, char* nomeEditor) {
    Celula* aux = l->ini;
    Celula* ant;

    while (aux) {
        if (!strcmp(retornaNomeEditor(aux->editor), nomeEditor))
            break;
        ant = aux;
        aux = aux->prox;
    }

    if (!aux) return NULL;

    return aux->editor;
}

void destroiListaEditor(ListaEdi* l) {
    Celula* aux = l->ini;
    Celula* prox;

    while (aux) {
        prox = aux->prox;
        destroiEditor(aux->editor);
        free(aux);
        aux = prox;
    }

    free(l);
}
