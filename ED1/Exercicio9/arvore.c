#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv {
    Aluno* info;
    Arv* esq;
    Arv* dir;
};

Arv* arvCriaVazia(void) {
    return NULL;
}

Arv* arvCria(Aluno* aluno, Arv* e, Arv* d) {
    Arv* arv = (Arv*)malloc(sizeof(Arv));
    arv->info = aluno;
    arv->esq = e;
    arv->dir = d;

    return arv;
}

Arv* arvLibera(Arv* a) {
    if (!arvVazia(a)) {
        arvLibera(a->esq);
        arvLibera(a->dir);
        free(a);
    }
    return NULL;
}

int arvVazia(Arv* a) {
    if (!a)
        return 1;
    return 0;
}

int arvPertence(Arv* a, char* nome) {
    if (arvVazia(a))
        return 0;
    else
        return !strcmp(nome, retornaNome(info(a))) ||
               arvPertence(a->esq, nome) ||
               arvPertence(a->dir, nome);
}

void arvImprime(Arv* a) {
    printf("<");
    if (!arvVazia(a)) {
        printf("%s", retornaNome(info(a)));
        arvImprime(a->esq);
        arvImprime(a->dir);
    }
    printf(">");
}

Arv* arvPai(Arv* a, char* nome) {
    if (arvVazia(a))
        return NULL;

    if ((!arvVazia(a->esq) && !strcmp(retornaNome(info(a->esq)), nome)) ||
        (!arvVazia(a->dir) && !strcmp(retornaNome(info(a->dir)), nome)))
        return a;

    Arv* aux = arvPai(a->esq, nome);
    if (arvVazia(aux))
        aux = arvPai(a->dir, nome);
    return aux;
}

int folhas(Arv* a) {
    if (arvVazia(a->esq) && arvVazia(a->dir))
        return 1;
    else if (!arvVazia(a->esq) && arvVazia(a->dir))
        return folhas(a->esq);
    else if (arvVazia(a->esq) && !arvVazia(a->dir))
        return folhas(a->dir);
    return folhas(a->esq) + folhas(a->dir);
}

int ocorrencias(Arv* a, char* nome) {
    if (arvVazia(a))
        return 0;

    if (!strcmp(nome, retornaNome(info(a))))
        return 1 + ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);

    return ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
}

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int altura(Arv* a) {
    if (arvVazia(a))
        return -1;
    else
        return 1 + max2(altura(a->esq), altura(a->dir));
}

Aluno* info(Arv* a) {
    return a->info;
}