#ifndef Lista_H
#define Lista_H

#include "aluno.h"

typedef struct lista Lista;

Lista* inicializaLista();

Lista* insereInicioLista(Lista* l, Aluno* a);

void imprimeLista(Lista* l);

Lista* removeAlunoLista(Lista* l, int mat);

void destroiLista(Lista* l);

#endif