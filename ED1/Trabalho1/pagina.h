#ifndef Pagina_H
#define Pagina_H

#include "lista.h"

typedef struct pagina Pagina;

Pagina* inicializaPagina(char* nome, char* arquivo);

void imprimePagina(Pagina* p);

char* retornaNomePagina(Pagina* p);

char* retornaArquivoPagina(Pagina* p);

Lista* retornaContribuicoesPagina(Pagina* p);

Lista* retornaLinksPagina(Pagina* p);

void destroiPagina(Pagina* p);

#endif
