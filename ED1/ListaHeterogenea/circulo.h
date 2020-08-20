#ifndef CIRCULO_H

#define CIRCULO_H

typedef struct circulo Circulo;

Circulo* inicializaCirculo(float r, int id);

float calculaAreaCirculo(Circulo* c);

void imprimeCirculo(Circulo* c);

int retornaIdCirculo(Circulo* c);

void destroiCirculo(Circulo* c);

#endif