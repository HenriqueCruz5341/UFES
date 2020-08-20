#ifndef RETANGULO_H

#define RETANGULO_H

typedef struct retangulo Retangulo;

Retangulo* inicializaRetangulo(float b, float h, int id);

float calculaAreaRetangulo(Retangulo* r);

void imprimeRetangulo(Retangulo* r);

int retornaIdRetangulo(Retangulo* r);

void destroiRetangulo(Retangulo* r);

#endif