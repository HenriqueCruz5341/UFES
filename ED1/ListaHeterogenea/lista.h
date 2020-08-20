#ifndef LISTA_h

#define LISTA_H

#include "circulo.h"
#include "retangulo.h"
#include "triangulo.h"

typedef struct lista Lista;

Lista* inicializaLista();

void insereItemLista(Lista* l, void* item, int tipo);

void removeItemLista(Lista* l, void* item);

void imprimeLista(Lista* l);

float calculaAreaTotal(Lista* l);

void destroiLista(Lista* l);

#endif