#ifndef ARVORE_H
#define ARVORE_H

#include "aluno.h"

typedef struct arv Arv;

Arv* arvCriaVazia(void);

Arv* arvCria(Aluno* aluno, Arv* e, Arv* d);

Arv* arvLibera(Arv* a);

int arvVazia(Arv* a);

int arvPertence(Arv* a, char* nome);

void arvImprime(Arv* a);

Arv* arvPai(Arv* a, char* nome);

int folhas(Arv* a);

int ocorrencias(Arv* a, char* nome);

int altura(Arv* a);

Aluno* info(Arv* a);

#endif