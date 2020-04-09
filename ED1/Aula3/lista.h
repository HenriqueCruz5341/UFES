#ifndef Lista_H
#define Lista_H

#include "aluno.h"

typedef struct lista Lista;

Lista* inicializaLista();

void insereInicioLista(Lista* l, Aluno* a);

void insereFimLista(Lista* l, Aluno* a);

void imprimeLista(Lista* l);

Aluno* removeAlunoLista(Lista* l, int mat);

void destroiLista(Lista* l);

#endif