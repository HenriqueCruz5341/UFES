#ifndef Link_H
#define Link_H

typedef struct link Link;

#include "pagina.h"

Link* inicializaLink(Pagina* origem, Pagina* destino);

Pagina* retornaOrigemLink(Link* l);

Pagina* retornaDestinoLink(Link* l);

void destroiLink(Link* l);

#endif
