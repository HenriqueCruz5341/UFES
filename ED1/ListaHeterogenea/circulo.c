#include "circulo.h"

#include <stdio.h>
#include <stdlib.h>

struct circulo {
    int id;
    float raio;
};

Circulo* inicializaCirculo(float r, int id) {
    Circulo* circ = (Circulo*)malloc(sizeof(Circulo));
    circ->id = id;
    circ->raio = r;

    return circ;
}

float calculaAreaCirculo(Circulo* c) {
    return 3.14 * c->raio * c->raio;
}

void imprimeCirculo(Circulo* c) {
    printf("CIRCULO DE RAIO: %.2f", c->raio);
}

int retornaIdCirculo(Circulo* c) {
    return c->id;
}

void destroiCirculo(Circulo* c) {
    free(c);
}
