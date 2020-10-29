#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

struct lista {
    Aluno* aluno;
    Lista* prox;
    Lista* ant;
};

Lista* inicializaLista() {
    return NULL;
}

Lista* insereInicioLista(Lista* l, Aluno* a) {
    Lista* nova = (Lista*)malloc(sizeof(Lista));

    nova->aluno = a;
    nova->ant = NULL;
    nova->prox = l;

    if (l != NULL)
        l->ant = nova;

    return nova;
}

void imprimeLista(Lista* l) {
    Lista* aux = l;
    int i = 0;

    if (l == NULL) {
        printf("Lista vazia!\n");
    }

    while (aux != NULL) {
        printf("Aluno: %d\n\t", i);
        imprimeAluno(aux->aluno);
        i++;
        aux = aux->prox;
    }
}

Lista* removeAlunoLista(Lista* l, int mat) {
    Lista* aux = l;

    if (aux == NULL)
        return NULL;

    while (aux != NULL && retornaMatricula(aux->aluno) != mat)
        aux = aux->prox;

    if (aux == NULL)
        return l;

    //se nao eh primeiro
    if (aux->ant != NULL)
        aux->ant->prox = aux->prox;
    else {
        l = aux->prox;
        if (l)
            l->ant = NULL;
    }

    //se nao eh ultimo
    if (aux->prox != NULL)
        aux->prox->ant = aux->ant;
    else if (l) //necessario
        aux->ant->prox = NULL;

    free(aux);

    return l;
}

void destroiLista(Lista* l) {
    Lista* aux = l;
    Lista* prox;

    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
}
