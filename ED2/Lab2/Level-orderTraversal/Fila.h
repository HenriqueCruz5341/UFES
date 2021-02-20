#ifndef Fila_H
#define Fila_H

typedef struct FilaComVetor Fila;

Fila* inicializaFila();

void insereFila(Fila* f, void* item);

void* retiraFila(Fila* f);

void destroiFila(Fila* f);

#endif