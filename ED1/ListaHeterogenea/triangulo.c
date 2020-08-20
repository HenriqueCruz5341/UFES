#include "triangulo.h"

#include <stdio.h>
#include <stdlib.h>

struct triangulo {
    int id;
    float base;
    float altura;
};

Triangulo* inicializaTriangulo(float b, float h, int id) {
    Triangulo* triangulo = (Triangulo*)malloc(sizeof(Triangulo));
    triangulo->base = b;
    triangulo->altura = h;
    triangulo->id = id;

    return triangulo;
}

float calculaAreaTriangulo(Triangulo* t) {
    return (t->base * t->altura) / 2;
}

void imprimeTriangulo(Triangulo* t) {
    printf("TRIANGULO DE BASE: %.2f, E ALTURA: %.2f", t->base, t->altura);
}

int retornaIdTriangulo(Triangulo* t) {
    return t->id;
}

void destroiTriangulo(Triangulo* t) {
    free(t);
}
