#ifndef Fila_H
#define Fila_H

// typedef struct FilaComVetor Fila;

typedef struct FilaComLista Fila;

Fila* inicializaFila();

void insereFila(Fila* f, int* num);

void retiraFila(Fila* f);

void imprimeFila(Fila* f);

void destroiFila(Fila* f);

#endif