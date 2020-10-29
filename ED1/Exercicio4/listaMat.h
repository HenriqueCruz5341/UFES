#ifndef Lista_H
#define Lista_H

#include "matriz.h"

typedef struct lista Lista;

Lista* inicializaLista();

void insereInicioLista(Lista* l, Matriz* m);

void insereFimLista(Lista* l, Matriz* m);

void imprimeLista(Lista* l);

Matriz* removeMatrizLista(Lista* l, int index);

void destroiLista(Lista* l);

#endif