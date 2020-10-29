#include <stdio.h>

#include "listaMat.h"
#include "matriz.h"

int main() {
    Lista* lista = inicializaLista();
    int i, j;
    Matriz* mat1;
    Matriz* mat2;
    Matriz* mat3;
    Matriz* matrizRemovida;

    mat1 = inicializaMatriz(3, 4);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            modificaElemento(mat1, i, j, i + j);

    mat2 = inicializaMatriz(4, 5);
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            modificaElemento(mat2, i, j, i + j);

    mat3 = inicializaMatriz(5, 6);
    for (i = 0; i < 5; i++)
        for (j = 0; j < 6; j++)
            modificaElemento(mat3, i, j, i + j);

    insereInicioLista(lista, mat1);
    insereFimLista(lista, mat2);
    insereInicioLista(lista, mat3);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    matrizRemovida = removeMatrizLista(lista, 0);
    imprimeLista(lista);
    printf("\nMatriz Removida:\n");
    imprimeMatriz(matrizRemovida);
    printf("------------------------------------------------\n");

    matrizRemovida = removeMatrizLista(lista, 1);
    imprimeLista(lista);
    printf("\nMatriz Removida:\n");
    imprimeMatriz(matrizRemovida);
    printf("------------------------------------------------\n");

    matrizRemovida = removeMatrizLista(lista, 0);
    imprimeLista(lista);
    printf("\nMatriz Removida:\n");
    imprimeMatriz(matrizRemovida);
    printf("------------------------------------------------\n");

    insereInicioLista(lista, mat1);
    insereInicioLista(lista, mat2);
    insereFimLista(lista, mat3);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    matrizRemovida = removeMatrizLista(lista, 1);
    imprimeLista(lista);
    printf("\nMatriz Removida:\n");
    imprimeMatriz(matrizRemovida);
    printf("------------------------------------------------\n");

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);

    destroiLista(lista);

    return 0;
}