#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

struct circulo{
    float raio;
    Ponto* centro;
};

Circulo* circulo_cria (float x, float y, float r){
    Circulo *circ = (Circulo *)malloc(sizeof(Circulo));
    
    if(circ == NULL){
        printf("Nao foi possivel alocar circulo\n");
        return circ;
    }
    
    circ->raio = r;
    circ->centro = pto_cria(x, y);
    
    if(circ->centro == NULL){
        free(circ);
        circ = NULL;
    }
    
    return circ;
}

void circulo_libera(Circulo *c){
    if(c != NULL){
        pto_libera(c->centro);
        free(c);
    }
}