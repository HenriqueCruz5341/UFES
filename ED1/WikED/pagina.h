#ifndef Pagina_H
#define Pagina_H

#include "listaCon.h"

typedef struct pagina Pagina;

#include "listaLin.h"

Pagina* inicializaPagina(char* nome, char* arquivo);

char* retornaNomePagina(Pagina* p);

char* retornaArquivoPagina(Pagina* p);

ListaCon* retornaContribuicoesPagina(Pagina* p);

ListaLin* retornaLinksPagina(Pagina* p);

void destroiPagina(Pagina* p);

#endif
