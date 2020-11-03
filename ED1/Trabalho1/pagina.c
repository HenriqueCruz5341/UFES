#include "pagina.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

struct pagina {
    char* nome;
    char* arquivo;
    Lista* contribuicoes;
    Lista* links;
};

Pagina* inicializaPagina(char* nome, char* arquivo) {
    Pagina* pagina = (Pagina*)malloc(sizeof(Pagina));

    pagina->nome = strdup(nome);
    pagina->arquivo = strdup(arquivo);
    pagina->contribuicoes = inicializaLista();
    pagina->links = inicializaLista();

    return pagina;
}

void imprimePagina(Pagina* p) {
}

char* retornaNomePagina(Pagina* p) {
    return p->nome;
}

char* retornaArquivoPagina(Pagina* p) {
    return p->arquivo;
}

Lista* retornaContribuicoesPagina(Pagina* p) {
    return p->contribuicoes;
}

Lista* retornaLinksPagina(Pagina* p) {
    return p->links;
}

void destroiPagina(Pagina* p) {
    if (p) {
        if (p->nome) free(p->nome);
        if (p->arquivo) free(p->arquivo);
        if (p->links) destroiLista(p->links);
        if (p->contribuicoes) destroiLista(p->contribuicoes);
    }

    free(p);
}