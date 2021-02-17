#ifndef PILHAOPERADOR_H
#define PILHAOPERADOR_H

typedef struct pilhaOperador PilhaOperador;

PilhaOperador* inicializaPilhaOperador();

void pushPilhaOperador(PilhaOperador* p, int num);

char popPilhaOperador(PilhaOperador* p);

void imprimePilhaOperador(PilhaOperador* p);

void destroiPilhaOperador(PilhaOperador* p);

#endif