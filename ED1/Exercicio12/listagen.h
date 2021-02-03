#ifndef LISTAGEN_H
#define LISTAGEN_H

#include <stdio.h>

typedef struct listagen ListaGen;

ListaGen *criaLista();

ListaGen *insereLista(ListaGen *lista, void *item);

ListaGen *retiraLista(ListaGen *lista, int (*cb)(void *, void *), void *chave);

int percorreLista(ListaGen *lista, int (*cb)(void *, void *), void *dado);

void liberaLista(ListaGen *lista);

#endif