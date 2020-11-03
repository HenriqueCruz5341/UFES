#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#include "professor.h"

#define PROF 0
#define ALU 1

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

    nova->tipo = tipo;
    nova->item = item;
    nova->prox = NULL;

    if (!l->fim)
        l->ini = nova;
    else
        l->fim->prox = nova;

    l->fim = nova;
}

void imprimeLista(Lista* l) {
    Celula* aux = l->ini;

    printf("\n==| Imprimindo Lista |==\n");

    while (aux) {
        if (aux->tipo == ALU)
            imprimeAluno(aux->item);
        else if (aux->tipo == PROF)
            imprimeProfessor(aux->item);

        aux = aux->prox;
    }
}

float valorChurrasco(Lista* l) {
    Celula* aux;
    float valor = 0;

    for (aux = l->ini; aux; aux = aux->prox) {
        if (aux->tipo == ALU)
            valor += 30;
        else if (aux->tipo == PROF)
            valor += retornaSalario(aux->item) * 0.02;
    }

    return valor;
}

void destroiLista(Lista* l) {
    Celula* aux = l->ini;
    Celula* prox;

    while (aux) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(l);
}