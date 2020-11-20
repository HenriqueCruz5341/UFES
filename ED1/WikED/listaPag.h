#ifndef ListaPag_H
#define ListaPag_H

#include "pagina.h"

typedef struct listaPag ListaPag;

ListaPag* inicializaListaPagina();

void inserePagina(ListaPag* l, Pagina* p);

void removePagina(ListaPag* l, char* nomePagina);

Pagina* buscaPagina(ListaPag* l, char* nomePagina);

Pagina* buscaPaginaIndex(ListaPag* l, int index);

int verificaCaminho(Pagina* origem, Pagina* destino);

void destroiListaPagina(ListaPag* l, int tudo);

#endif
