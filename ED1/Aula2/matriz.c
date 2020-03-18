#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz {
    int* inicio;
    int numLin;
    int numCol;
};

Matriz* inicializaMatriz(int nlinhas, int ncolunas) {
    Matriz* mat = (Matriz*) malloc(sizeof (Matriz));
    if (mat == NULL) {
        printf("Nao foi possivel inicializar a matriz.");
        return mat;
    }

    mat->numLin = nlinhas;
    mat->numCol = ncolunas;
    mat->inicio = (int*) malloc(nlinhas * ncolunas * sizeof (int));

    if (mat->inicio == NULL) {
        free(mat);
        printf("Erro ao inicializar o inicio da matriz.");
        return mat;
    }

    return mat;
}

void modificaElemento(Matriz* mat, int linha, int coluna, int elem) {
    if (mat == NULL) {
        printf("Erro!");
    } else {
        mat->inicio[linha * mat->numCol + coluna] = elem;
    }
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
    if (mat == NULL) {
        printf("Erro!");
        return 0;
    } else {
        return mat->inicio[linha * mat->numCol + coluna];
    }
}

int recuperaNColunas(Matriz* mat) {
    if (mat == NULL) {
        printf("Erro!");
        return 0;
    }
    return mat->numCol;
}

int recuperaNLinhas(Matriz* mat) {
    if (mat == NULL) {
        printf("Erro!");
        return 0;
    }
    return mat->numLin;
}

Matriz* transposta(Matriz* mat){
    Matriz *trp = inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));
    int elemAux;

    for(int i = 0; i< recuperaNLinhas(mat); i++){
        for (int j = 0; j < recuperaNColunas(mat); j++)
        {   
            elemAux = recuperaElemento(mat, i, j);
            modificaElemento(trp, j, i, elemAux);
        }
    }

    return trp;
}

Matriz* multiplicacao(Matriz* mat1, Matriz* mat2){
    Matriz *mult = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));

    for(int i = 0; i < recuperaNLinhas(mat1); i++){
        for(int j = 0; j < recuperaNColunas(mat2); j++){
            modificaElemento(mult, i, j, 0);
        }
    }

    for(int i = 0; i < recuperaNLinhas(mat1); i++){
        for(int j = 0; j < recuperaNLinhas(mat2); j++){
            for(int k = 0; k < recuperaNColunas(mat2); k++){
                int elemAux = 0;
                elemAux = recuperaElemento(mat1, i, j) * recuperaElemento(mat2, j, k); 
                modificaElemento(mult, i, k, recuperaElemento(mult, i, k) + elemAux);
            }
        }
    }

    return mult;
}

void imprimeMatriz(Matriz* mat){
    if (mat == NULL) {
        printf("Erro!");
    }else{
        for(int i = 0; i < recuperaNLinhas(mat); i++){
            for(int j = 0; j < recuperaNColunas(mat); j++){
                printf("%d ", recuperaElemento(mat, i, j));
            }
            printf("\n");
        }
    }
}

void destroiMatriz(Matriz* mat) {
    if (mat != NULL) {
        if (mat->inicio != NULL)
            free(mat->inicio);
        free(mat);
    }
}