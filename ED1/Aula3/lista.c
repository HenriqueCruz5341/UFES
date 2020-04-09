#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula {
    Aluno* aluno;
    Celula* prox;
};

struct lista {
    Celula* pri;
    Celula* ult;
};

Lista* inicializaLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->pri = NULL;
    lista->ult = NULL;

    return lista;
}

void insereInicioLista(Lista* l, Aluno* a) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->aluno = a;
    nova->prox = l->pri;
    l->pri = nova;

    if (l->ult == NULL) l->ult = nova;
}

void insereFimLista(Lista* l, Aluno* a) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->aluno = a;
    nova->prox = NULL;

    if (l->pri == NULL)
        l->pri = nova;
    else
        l->ult->prox = nova;

    l->ult = nova;
}

void imprimeLista(Lista* l) {
    Celula* aux;

    for (aux = l->pri; aux != NULL; aux = aux->prox)
        imprimeAluno(aux->aluno);

    if (l->pri != NULL && l->ult != NULL) {
        printf("\nInicio: ");
        imprimeAluno(l->pri->aluno);
        printf("Fim: ");
        imprimeAluno(l->ult->aluno);
    } else {
        printf("Lista vazia!\n");
    }
}

Aluno* removeAlunoLista(Lista* l, int mat) {
    Celula* aux = l->pri;
    Celula* ant;
    Aluno* aluno;

    while (aux != NULL && retornaMatricula(aux->aluno) != mat) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
        return NULL;

    aluno = aux->aluno;

    if (l->pri == aux && l->ult == aux) {
        l->pri = NULL;
        l->ult = NULL;
    } else if (l->ult == aux) {
        l->ult = ant;
        ant->prox = NULL;
    } else if (l->pri == aux) {
        l->pri = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    free(aux);

    return aluno;
}

void destroiLista(Lista* l) {
    Celula* aux = l->pri;
    Celula* prox;

    while (aux != NULL) {
        prox = aux->prox;
        destroiAluno(aux->aluno);
        free(aux);
        aux = prox;
    }

    free(l);
}