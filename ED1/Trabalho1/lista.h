#ifndef Lista_H
#define Lista_H

#include "pagina.h"

typedef struct lista Lista;

Lista* inicializaLista();

void insereItem(Lista* l, void* item, int tipo);

void removeContribuicao(Lista* l, char* nomePagina, char* nomeEditor, char* nomeArquivo);

void removeLink(Lista* l, Pagina* origem, Pagina* destino);

void removePagina(Lista* l, char* nomePagina);

void imprimeLista(Lista* l);

void destroiLista(Lista* l);

#endif
