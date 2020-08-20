#include <stdio.h>

#include "circulo.h"
#include "lista.h"
#include "retangulo.h"
#include "triangulo.h"

#define CIR 0
#define RET 1
#define TRI 2

int main() {
    Circulo* circulo = inicializaCirculo(5, 1);
    Retangulo* retangulo = inicializaRetangulo(10, 2, 2);
    Triangulo* triangulo = inicializaTriangulo(10, 5, 3);

    Lista* lista = inicializaLista();

    insereItemLista(lista, circulo, CIR);
    insereItemLista(lista, retangulo, RET);
    insereItemLista(lista, triangulo, TRI);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);
    printf("Area total da lista: %.2f\n", calculaAreaTotal(lista));

    removeItemLista(lista, circulo);
    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    removeItemLista(lista, triangulo);
    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    insereItemLista(lista, circulo, CIR);
    insereItemLista(lista, triangulo, TRI);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    removeItemLista(lista, circulo);
    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    destroiLista(lista);

    destroiCirculo(circulo);
    destroiRetangulo(retangulo);
    destroiTriangulo(triangulo);

    return 0;
}