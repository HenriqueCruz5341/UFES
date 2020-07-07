#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int mat;
    char *nome;
    float cr;
};

Aluno *inicializaAluno(int mat, char *nome, float cr) {
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    aluno->mat = mat;
    aluno->cr = cr;
    aluno->nome = strdup(nome);

    return aluno;
}

void imprimeAluno(Aluno *a) {
    printf("Matricula: %d, Nome: %s, CR: %.2f\n", a->mat, a->nome, a->cr);
}

int retornaMatricula(Aluno *a) {
    return a->mat;
}

char *retornaNome(Aluno *a) {
    return a->nome;
}

float retornaCr(Aluno *a) {
    return a->cr;
}

void destroiAluno(Aluno *a) {
    if (a != NULL) {
        if (a->nome != NULL) free(a->nome);
        free(a);
    }
}
