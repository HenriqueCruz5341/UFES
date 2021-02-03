#ifndef LISTAALUNO_H
#define LISTAALUNO_H

#include <stdio.h>

#include "aluno.h"
#include "listagen.h"

ListaGen *retiraAluno(ListaGen *lista, int matricula);

int pertenceAluno(ListaGen *lista, int matricula);

void imprimeListaAlunos(ListaGen *lista);

float mediaTurma(ListaGen *lista);

#endif