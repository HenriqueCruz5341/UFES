#include "BST.h"

#include <stdio.h>
#include <stdlib.h>

struct bst {
    int chave;
    BST* esq;
    BST* dir;
};

BST* bstCria(void) {
    return NULL;
}

void bstImprime(BST* a) {
    if (a) {
        bstImprime(a->esq);
        printf("%d, ", a->chave);
        bstImprime(a->dir);
    }
}

BST* bstBusca(BST* a, int chave) {
    return NULL;
}

BST* bstInsere(BST* a, int chave) {
    if (!a) {
        a = (BST*)malloc(sizeof(BST));
        a->chave = chave;
        a->esq = a->dir = NULL;
    } else if (a->chave > chave)
        a->esq = bstInsere(a->esq, chave);
    else if (a->chave < chave)
        a->dir = bstInsere(a->dir, chave);

    return a;
}

BST* bstRetira(BST* a, int chave) {
    return NULL;
}

int bstAltura(BST* a) {
    if (a) {
        int alturaE = bstAltura(a->esq);
        int alturaD = bstAltura(a->dir);
        return 1 + ((alturaE > alturaD) ? alturaE : alturaD);
    }

    return -1;
}

void bstVisitPreOrder(BST* a, void (*visit)(void*)) {
    if (a) {
        visit(&a->chave);
        bstVisitPreOrder(a->esq, visit);
        bstVisitPreOrder(a->dir, visit);
    }
}

void bstVisitInOrder(BST* a, void (*visit)(void*)) {
    if (a) {
        bstVisitInOrder(a->esq, visit);
        visit(&a->chave);
        bstVisitInOrder(a->dir, visit);
    }
}

void bstVisitPosOrder(BST* a, void (*visit)(void*)) {
    if (a) {
        bstVisitPosOrder(a->esq, visit);
        bstVisitPosOrder(a->dir, visit);
        visit(&a->chave);
    }
}

BST* bstLibera(BST* a) {
    if (a) {
        bstLibera(a->esq);
        bstLibera(a->dir);
        free(a);
    }

    return NULL;
}

/*
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
*/