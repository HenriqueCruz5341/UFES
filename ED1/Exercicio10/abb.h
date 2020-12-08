#ifndef ABB_H
#define ABB_H

#include "aluno.h"

typedef struct arv Arv;

Arv* abbCria(void);

void abbImprime(Arv* a);

Arv* abbBusca(Arv* a, int chave);

Arv* abbInsere(Arv* a, Aluno* aluno);

Arv* abbRetira(Arv* a, int chave);

Arv* abbLibera(Arv* a);

#endif