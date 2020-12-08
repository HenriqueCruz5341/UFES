#include "abb.h"

#include <stdio.h>
#include <stdlib.h>

struct arv {
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};

Arv* abbCria(void) {
    return NULL;
}

void abbImprime(Arv* a) {
    if (a) {
        abbImprime(a->esq);
        imprimeAluno(a->aluno);
        abbImprime(a->dir);
    }
}

Arv* abbBusca(Arv* a, int chave) {
    if (!a)
        return NULL;
    else if (retornaMatricula(a->aluno) > chave)
        return abbBusca(a->esq, chave);
    else if (retornaMatricula(a->aluno) < chave)
        return abbBusca(a->dir, chave);
    else
        return a;
}

Arv* abbInsere(Arv* a, Aluno* aluno) {
    if (!a) {
        a = (Arv*)malloc(sizeof(Arv));
        a->aluno = aluno;
        a->esq = a->dir = NULL;
    } else if (retornaMatricula(a->aluno) > retornaMatricula(aluno))
        a->esq = abbInsere(a->esq, aluno);
    else
        a->dir = abbInsere(a->dir, aluno);

    return a;
}

Arv* abbRetira(Arv* a, int chave) {
    if (!a)
        return NULL;
    else if (retornaMatricula(a->aluno) > chave)
        a->esq = abbRetira(a->esq, chave);
    else if (retornaMatricula(a->aluno) < chave)
        a->dir = abbRetira(a->dir, chave);
    else {
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            a = NULL;
        } else if (a->esq == NULL) {
            Arv* t = a;
            a = a->dir;
            free(t);
        } else if (a->dir == NULL) {
            Arv* t = a;
            a = a->esq;
            free(t);
        } else {
            Arv* f = a->esq;
            while (f->dir)
                f = f->dir;

            Aluno* t = a->aluno;
            a->aluno = f->aluno;
            f->aluno = t;

            a->esq = abbRetira(a->esq, chave);
        }
    }

    return a;
}

Arv* abbLibera(Arv* a) {
    if (a) {
        abbLibera(a->esq);
        abbLibera(a->dir);
        free(a);
    }
    return NULL;
}
