#include "listaPag.h"

#include <stdlib.h>
#include <string.h>

#include "impressao.h"

typedef struct celula Celula;

struct celula {
    Pagina* pagina;
    Celula* prox;
};

struct listaPag {
    Celula* ini;
    Celula* fim;
};

ListaPag* inicializaListaPagina() {
    ListaPag* listaPag = (ListaPag*)malloc(sizeof(ListaPag));

    listaPag->ini = NULL;
    listaPag->fim = NULL;

    return listaPag;
}

void inserePagina(ListaPag* l, Pagina* p) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->pagina = p;
    nova->prox = NULL;

    if (!l->ini)
        l->ini = nova;
    else
        l->fim->prox = nova;

    l->fim = nova;
}

void removePagina(ListaPag* l, char* nomePagina) {
    Celula* aux = l->ini;
    Celula* ant;

    while (aux) {
        if (!strcmp(retornaNomePagina(aux->pagina), nomePagina))
            break;
        ant = aux;
        aux = aux->prox;
    }

    if (!aux) {
        imprimeLog("ERRO: não existe a pagina ", nomePagina);
        return;
    }

    if (l->ini == l->fim) {
        l->ini = NULL;
        l->fim = NULL;
    } else if (l->ini == aux) {
        l->ini = aux->prox;
    } else if (l->fim == aux) {
        l->fim = ant;
        ant->prox = NULL;
    } else {
        ant->prox = aux->prox;
    }

    ListaLin* listaLin;
    Link* link;
    Celula* aux1 = l->ini;

    while (aux1) {
        listaLin = retornaLinksPagina(aux1->pagina);
        link = buscaOrigemLink(listaLin, nomePagina);
        if (link)
            removeLink(listaLin, retornaNomePagina(retornaOrigemLink(link)), nomePagina);

        aux1 = aux1->prox;
    }

    destroiPagina(aux->pagina);
    free(aux);
}

Pagina* buscaPagina(ListaPag* l, char* nomePagina) {
    Celula* aux = l->ini;
    Celula* ant;

    while (aux) {
        if (!strcmp(retornaNomePagina(aux->pagina), nomePagina))
            break;
        ant = aux;
        aux = aux->prox;
    }

    if (!aux) return NULL;

    return aux->pagina;
}

Pagina* buscaPaginaIndex(ListaPag* l, int index) {
    Celula* aux = l->ini;
    int i = 0;

    while (aux && i != index) {
        i++;
        aux = aux->prox;
    }

    if (!aux) {
        // imprimeLog("ERRO: index de pagina nao encontrado", NULL); //Comentado pq estava poluindo o arquivo log.txt
        return NULL;
    }

    return aux->pagina;
}

void buscaProfunda(ListaPag* visitadas, Pagina* pagina) {
    inserePagina(visitadas, pagina);

    Link* link;
    int i = 0;

    for (link = buscaLinkIndex(retornaLinksPagina(pagina), i); link; i++,
        link = buscaLinkIndex(retornaLinksPagina(pagina), i)) {
        Pagina* destino = retornaDestinoLink(link);
        if (!buscaPagina(visitadas, retornaNomePagina(destino)))
            buscaProfunda(visitadas, destino);
    }
}

int verificaCaminho(Pagina* origem, Pagina* destino) {
    ListaPag* visitadas = inicializaListaPagina();
    int achou = 0;

    buscaProfunda(visitadas, origem);

    if (buscaPagina(visitadas, retornaNomePagina(destino)))
        achou = 1;

    destroiListaPagina(visitadas, 0);

    return achou;
}

void destroiListaPagina(ListaPag* l, int tudo) {
    Celula* aux = l->ini;
    Celula* prox;

    while (aux) {
        prox = aux->prox;
        if (tudo)
            destroiPagina(aux->pagina);
        free(aux);
        aux = prox;
    }

    free(l);
}
