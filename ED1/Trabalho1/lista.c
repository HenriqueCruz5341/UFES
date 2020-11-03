#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contribuicao.h"
#include "editor.h"
#include "link.h"
#include "pagina.h"

#define CON 0
#define EDI 1
#define LIN 2
#define PAG 3

typedef struct celula Celula;

struct celula {
    void* item;
    int tipo;
    Celula* prox;
};

struct lista {
    Celula* ini;
    Celula* fim;
};

Lista* inicializaLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->ini = NULL;
    lista->fim = NULL;

    return lista;
}

void insereItem(Lista* l, void* item, int tipo) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->item = item;
    nova->tipo = tipo;
    nova->prox = NULL;

    if (!l->ini)
        l->ini = nova;
    else
        l->fim->prox = nova;

    l->fim = nova;
}

void removeContribuicao(Lista* l, char* nomePagina, char* nomeEditor, char* nomeArquivo) {
    Celula* aux = (Celula*)malloc(sizeof(Celula));

    for (aux = l->ini; !strcmp(retornaNomePagina(aux->item), nomePagina) || aux == NULL; aux = aux->prox)
        ;
}

void removeLink(Lista* l, Pagina* origem, Pagina* destino) {
}

void removePagina(Lista* l, char* nomePagina) {
}

void imprimeLista(Lista* l) {
}

void destroiLista(Lista* l) {
}
