#include "professor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor {
    int siape;
    char *nome;
    float salario;
};

Professor *inicializaProfessor(int siape, char *nome, float salario) {
    Professor *professor = (Professor *)malloc(sizeof(Professor));

    professor->siape = siape;
    professor->nome = strdup(nome);
    professor->salario = salario;
}

void imprimeProfessor(Professor *p) {
    printf("PROFESSOR: Siape: %d, Nome: %s, Salário: %.2f\n", p->siape, p->nome, p->salario);
}

int retornaSiape(Professor *p) {
    return p->siape;
}

char *retornaNomeProfessor(Professor *p) {
    return p->nome;
}

float retornaSalario(Professor *p) {
    return p->salario;
}

void destroiProfessor(Professor *p) {
    if (p) {
        if (p->nome) free(p->nome);
        free(p);
    }
}
