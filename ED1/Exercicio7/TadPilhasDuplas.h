#ifndef TadPilhasDuplas_H
#define TadPilhasDuplas_H

typedef struct pilhasDuplas PilhasDuplas;

PilhasDuplas* inicializaPilhas();

void pushPilha1(PilhasDuplas* pd, int* num);

void pushPilha2(PilhasDuplas* pd, int* num);

int* popPilha1(PilhasDuplas* pd);

int* popPilha2(PilhasDuplas* pd);

void imprimePilha1(PilhasDuplas* pd);

void imprimePilha2(PilhasDuplas* pd);

void destroiPilhas(PilhasDuplas* pd);

#endif