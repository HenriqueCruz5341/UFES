#include<stdio.h>
#include<stdlib.h>
#include "ponto.h"

struct ponto{
    float x;
    float y;
};

Ponto* pto_cria(float x, float y){
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    
    if(p == NULL){
        printf("Nao foi possivel alocar ponto\n");
        exit(1);
    }
    
    p->x = x;
    p->y = y;
    
    return p;
}

void pto_libera(Ponto *p){
    if(p != NULL){
        free(p);
    }
}

void pto_acessa(Ponto *p, float *x, float *y){
    if(p != NULL){
        *x = p->x;
        *y = p->y;
    }
}

void pto_atribui(Ponto *p, float *x, float *y){
    if(p != NULL){
        p->x = *x;
        p->y = *y;
    }
}

void pto_imprime(Ponto *p){
    printf("X: %.2f | Y: %.2f\n", p->x, p->y);
}