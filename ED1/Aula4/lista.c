#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula {
    Aluno* aluno;
    Celula* prox;
    Celula* ant;
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

void insereLista(Lista* l, Aluno* a) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->aluno = a;
    nova->prox = l->pri;
    nova->ant = NULL;
    l->pri = nova;

    if (l->ult == NULL)
        l->ult = nova;
    else
        nova->prox->ant = nova;
}

void imprimeLista(Lista* l) {
    Celula* p;

    for (p = l->pri; p != NULL; p = p->prox) {
        imprimeAluno(p->aluno);
    }
}

Celula* buscaAlunoLista(Lista* l, int mat) {
    Celula* p;

    for (p = l->pri; p != NULL; p = p->prox) {
        if (retornaMatricula(p->aluno) == mat)
            return p;
    }

    return NULL;
}

void removeAlunoLista(Lista* l, Aluno* a) {
    Celula* alRe = buscaAlunoLista(l, retornaMatricula(a));

    if (alRe != NULL) {
        if (alRe->ant == NULL && alRe->prox == NULL) {
            l->pri = NULL;
            l->ult = NULL;
        } else if (alRe->ant == NULL) {
            l->pri = alRe->prox;
            alRe->prox->ant = NULL;
        } else if (alRe->prox == NULL) {
            l->ult = alRe->ant;
            alRe->ant->prox = NULL;
        } else {
            alRe->ant->prox = alRe->prox;
            alRe->prox->ant = alRe->ant;
        }

        free(alRe);
    }
}

void destroiLista(Lista* l) {
    Celula* p = l->pri;
    Celula* aux;

    while (p != NULL) {
        aux = p->prox;
        free(p);
        p = aux;
    }

    free(l);
}