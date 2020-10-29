#ifndef Aluno_h
#define Aluno_h

typedef struct aluno Aluno;

Aluno *inicializaAluno(int mat, char *nome, float cr);

void imprimeAluno(Aluno *a);

int retornaMatricula(Aluno *a);

char *retornaNome(Aluno *a);

float retornaCr(Aluno *a);

void destroiAluno(Aluno *a);

#endif