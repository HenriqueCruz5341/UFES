#ifndef ListaEdi_H
#define ListaEdi_H

#include "editor.h"

typedef struct listaEdi ListaEdi;

ListaEdi* inicializaListaEditor();

void insereEditor(ListaEdi* l, Editor* e);

Editor* buscaEditor(ListaEdi* l, char* nomeEditor);

void destroiListaEditor(ListaEdi* l);

#endif
