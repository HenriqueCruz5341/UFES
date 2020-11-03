#ifndef Link_H
#define Link_H

#include "pagina.h"

typedef struct link Link;

Link* inicializaLink(Pagina* origem, Pagina* destino);

void imprimeLink(Link* l);

Pagina* retornaOrigemLink(Link* l);

Pagina* retornaDestinoLink(Link* l);

void destroiLink(Link* l);

#endif
