#ifndef ListaLin_H
#define ListaLin_H

typedef struct listaLin ListaLin;

#include "link.h"

ListaLin* inicializaListaLink();

void insereLink(ListaLin* l, Link* link);

void removeLink(ListaLin* l, char* nomeOrigem, char* nomeDestino);

Link* buscaLink(ListaLin* l, char* nomeOrigem, char* nomeDestino);

Link* buscaOrigemLink(ListaLin* l, char* nomeDestino);

Link* buscaLinkIndex(ListaLin* l, int index);

void destroiListaLink(ListaLin* l);

#endif
