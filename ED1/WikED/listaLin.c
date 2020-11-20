#include "listaLin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula {
    Link* link;
    Celula* prox;
};

struct listaLin {
    Celula* ini;
    Celula* fim;
};

ListaLin* inicializaListaLink() {
    ListaLin* listaLin = (ListaLin*)malloc(sizeof(ListaLin));

    listaLin->ini = NULL;
    listaLin->fim = NULL;

    return listaLin;
}

void insereLink(ListaLin* l, Link* link) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->link = link;
    nova->prox = NULL;

    if (!l->ini)
        l->ini = nova;
    else
        l->fim->prox = nova;

    l->fim = nova;
}

void removeLink(ListaLin* l, char* origem, char* destino) {
    Celula* aux = l->ini;
    Celula* ant;

    while (aux) {
        if (!strcmp(retornaNomePagina(retornaOrigemLink(aux->link)), origem) &&
            !strcmp(retornaNomePagina(retornaDestinoLink(aux->link)), destino))
            break;
        ant = aux;
        aux = aux->prox;
    }

    FILE* arq = fopen("log.txt", "a");
    if (arq == NULL) {
        printf("Arquivo invalido.\n");
        return;
    }

    if (!aux) {
        fprintf(arq, "ERRO: o link não existe\n");
        fclose(arq);
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

    destroiLink(aux->link);
    free(aux);
    fclose(arq);
}

Link* buscaLink(ListaLin* l, char* nomeOrigem, char* nomeDestino) {
    Celula* aux = l->ini;
    Celula* ant;

    while (aux) {
        if (!strcmp(retornaNomePagina(retornaOrigemLink(aux->link)), nomeOrigem) &&
            !strcmp(retornaNomePagina(retornaDestinoLink(aux->link)), nomeDestino))
            break;
        ant = aux;
        aux = aux->prox;
    }

    if (!aux) return NULL;

    return aux->link;
}

Link* buscaOrigemLink(ListaLin* l, char* nomeDestino) {
    Celula* aux = l->ini;
    Celula* ant;

    while (aux) {
        if (!strcmp(retornaNomePagina(retornaDestinoLink(aux->link)), nomeDestino))
            break;
        ant = aux;
        aux = aux->prox;
    }

    if (!aux) return NULL;

    return aux->link;
}

Link* buscaLinkIndex(ListaLin* l, int index) {
    Celula* aux = l->ini;
    int i = 0;

    while (aux && i != index) {
        i++;
        aux = aux->prox;
    }

    if (!aux) {
        // imprimeLog("ERRO: index de link nao encontrado", NULL); //Comentado pq estava poluindo o arquivo log.txt
        return NULL;
    }

    return aux->link;
}

void destroiListaLink(ListaLin* l) {
    Celula* aux = l->ini;
    Celula* prox;

    while (aux) {
        prox = aux->prox;
        destroiLink(aux->link);
        free(aux);
        aux = prox;
    }

    free(l);
}
