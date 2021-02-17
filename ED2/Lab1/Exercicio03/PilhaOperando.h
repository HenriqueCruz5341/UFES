#ifndef PILHAOPERANDO_H
#define PILHAOPERANDO_H

typedef struct pilhaOperando PilhaOperando;

PilhaOperando* inicializaPilhaOperando();

void pushPilhaOperando(PilhaOperando* p, double num);

double popPilhaOperando(PilhaOperando* p);

void imprimePilhaOperando(PilhaOperando* p);

void destroiPilhaOperando(PilhaOperando* p);

#endif