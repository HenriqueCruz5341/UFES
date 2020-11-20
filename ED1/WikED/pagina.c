#include "pagina.h"

#include <stdlib.h>
#include <string.h>

struct pagina {
    char* nome;
    char* arquivo;
    ListaCon* contribuicoes;
    ListaLin* links;
};

Pagina* inicializaPagina(char* nome, char* arquivo) {
    Pagina* pagina = (Pagina*)malloc(sizeof(Pagina));

    pagina->nome = strdup(nome);
    pagina->arquivo = strdup(arquivo);
    pagina->contribuicoes = inicializaListaContribuicao();
    pagina->links = inicializaListaLink();

    return pagina;
}

char* retornaNomePagina(Pagina* p) {
    return p->nome;
}

char* retornaArquivoPagina(Pagina* p) {
    return p->arquivo;
}

ListaCon* retornaContribuicoesPagina(Pagina* p) {
    return p->contribuicoes;
}

ListaLin* retornaLinksPagina(Pagina* p) {
    return p->links;
}

void destroiPagina(Pagina* p) {
    if (p) {
        if (p->nome) free(p->nome);
        if (p->arquivo) free(p->arquivo);
        if (p->links) destroiListaLink(p->links);
        if (p->contribuicoes) destroiListaContribuicao(p->contribuicoes);
    }

    free(p);
}