#ifndef LISTACIRC_H
#define LISTACIRC_H

typedef struct listaCirc ListaCirc;

ListaCirc* inicializaLista();

void populaListaCirc(ListaCirc* l, int qtd);

int removeListaCirc(ListaCirc* l, int pos);

int existeLider(ListaCirc* l);

void destroiListaCirc(ListaCirc* l);

#endif
