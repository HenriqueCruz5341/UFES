#ifndef TRIANGULO_H

#define TRIANGULO_H

typedef struct triangulo Triangulo;

Triangulo* inicializaTriangulo(float b, float h, int id);

float calculaAreaTriangulo(Triangulo* t);

void imprimeTriangulo(Triangulo* t);

int retornaIdTriangulo(Triangulo* t);

void destroiTriangulo(Triangulo* t);

#endif