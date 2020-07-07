#ifndef Lista_H
#define Lista_H

#include "aluno.h"

typedef struct lista Lista;

Lista* inicializaLista();

void insereLista(Lista* l, Aluno* a);

void imprimeLista(Lista* l);

void removeAlunoLista(Lista* l, Aluno* a);

void destroiLista(Lista* l);

#endif