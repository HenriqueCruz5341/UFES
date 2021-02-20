#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* inicializaPilha();

void pushPilha(Pilha* p, void* item);

void* popPilha(Pilha* p);

void imprimePilha(Pilha* p);

void destroiPilha(Pilha* p);

#endif