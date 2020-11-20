#include "link.h"

#include <stdio.h>
#include <stdlib.h>

struct link {
    Pagina* origem;
    Pagina* destino;
};

Link* inicializaLink(Pagina* origem, Pagina* destino) {
    Link* link = (Link*)malloc(sizeof(Link));

    link->origem = origem;
    link->destino = destino;

    return link;
}

Pagina* retornaOrigemLink(Link* l) {
    return l->origem;
}

Pagina* retornaDestinoLink(Link* l) {
    return l->destino;
}

void destroiLink(Link* l) {
    if (l)
        free(l);
}
