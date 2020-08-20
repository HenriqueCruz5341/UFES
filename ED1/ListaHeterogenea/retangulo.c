#include "retangulo.h"

#include <stdio.h>
#include <stdlib.h>

struct retangulo {
    int id;
    float base;
    float altura;
};

Retangulo* inicializaRetangulo(float b, float h, int id) {
    Retangulo* retangulo = (Retangulo*)malloc(sizeof(Retangulo));
    retangulo->base = b;
    retangulo->altura = h;
    retangulo->id = id;

    return retangulo;
}

float calculaAreaRetangulo(Retangulo* r) {
    return r->base * r->altura;
}

void imprimeRetangulo(Retangulo* r) {
    printf("RETANGULO DE BASE: %.2f, E ALTURA: %.2f", r->base, r->altura);
}

int retornaIdRetangulo(Retangulo* r) {
    return r->id;
}

void destroiRetangulo(Retangulo* r) {
    free(r);
}
