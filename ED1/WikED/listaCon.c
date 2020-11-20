#include "listaCon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"
#include "impressao.h"

typedef struct celula Celula;

struct celula {
    Contribuicao* contribuicao;
    Celula* prox;
};

struct listaCon {
    Celula* ini;
    Celula* fim;
};

ListaCon* inicializaListaContribuicao() {
    ListaCon* listaCon = (ListaCon*)malloc(sizeof(ListaCon));

    listaCon->ini = NULL;
    listaCon->fim = NULL;

    return listaCon;
}

void insereContribuicao(ListaCon* l, Contribuicao* c) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->contribuicao = c;
    nova->prox = NULL;

    if (!l->ini)
        l->ini = nova;
    else
        l->fim->prox = nova;

    l->fim = nova;
}

void removeContribuicao(ListaCon* l, char* nomeEditor, char* nomeArquivo) {
    Celula* aux = l->ini;
    Celula* ant;

    while (aux) {
        if (!strcmp(retornaArquivoContribuicao(aux->contribuicao), nomeArquivo))
            break;
        ant = aux;
        aux = aux->prox;
    }

    if (!aux) {
        imprimeLog("ERRO: contribuicao nao encontrada ", nomeArquivo);
        return;
    }

    if (strcmp(retornaNomeEditor(retornaEditorContribuicao(aux->contribuicao)), nomeEditor)) {
        imprimeLog("ERRO: editor nao eh dono ", nomeEditor);
        return;
    }

    setaRetiradaContribuicao(aux->contribuicao, 1);
}

Contribuicao* buscaContribuicaoIndex(ListaCon* l, int index) {
    Celula* aux = l->ini;
    int i = 0;

    while (aux && i != index) {
        i++;
        aux = aux->prox;
    }

    if (!aux) {
        // imprimeLog("ERRO: index de contribuicao nao encontrado", NULL); //Comentado pq estava poluindo o arquivo log.txt
        return NULL;
    }

    return aux->contribuicao;
}

void destroiListaContribuicao(ListaCon* l) {
    Celula* aux = l->ini;
    Celula* prox;

    while (aux) {
        prox = aux->prox;
        destroiContribuicao(aux->contribuicao);
        free(aux);
        aux = prox;
    }

    free(l);
}
