#ifndef ListaCon_H
#define ListaCon_H

#include "contribuicao.h"

typedef struct listaCon ListaCon;

ListaCon* inicializaListaContribuicao();

void insereContribuicao(ListaCon* l, Contribuicao* c);

void removeContribuicao(ListaCon* l, char* nomeEditor, char* nomeArquivo);

Contribuicao* buscaContribuicaoIndex(ListaCon* l, int index);

void destroiListaContribuicao(ListaCon* l);

#endif
