#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz {
    int* inicio;
    int nLin;
    int nCol;
};

Matriz* inicializaMatriz(int nlinhas, int ncolunas) {
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    if (mat == NULL) {
        printf("Não foi possivel inicializar a matriz.");
        return mat;
    }

    mat->inicio = (int*)malloc(sizeof(int) * nlinhas * ncolunas);
    mat->nLin = nlinhas;
    mat->nCol = ncolunas;

    if (mat->inicio == NULL) {
        free(mat);
        printf("Não foi possivel inicializar o inicio da matriz.");
    }

    return mat;
}

void modificaElemento(Matriz* mat, int linha, int coluna, int elem) {
    int nCol = recuperaNColunas(mat);

    mat->inicio[(nCol * linha) + coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
    int nCol = recuperaNColunas(mat);

    int elemento = mat->inicio[(linha * nCol) + coluna];
    return elemento;
}

int recuperaNColunas(Matriz* mat) {
    return mat->nCol;
}

int recuperaNLinhas(Matriz* mat) {
    return mat->nLin;
}

Matriz* transposta(Matriz* mat) {
    Matriz* trp = inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));

    for (int i = 0; i < recuperaNLinhas(trp); i++) {
        for (int j = 0; j < recuperaNColunas(trp); j++) {
            modificaElemento(trp, i, j, recuperaElemento(mat, j, i));
        }
    }

    return trp;
}

Matriz* multiplicacao(Matriz* mat1, Matriz* mat2) {
    Matriz* mlt = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));

    for (int i = 0; i < recuperaNLinhas(mlt); i++) {
        for (int j = 0; j < recuperaNColunas(mlt); j++) {
            int elem = 0;
            for (int k = 0; k < recuperaNColunas(mat1); k++) {
                elem += recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j);
            }
            modificaElemento(mlt, i, j, elem);
        }
    }

    return mlt;
}

void imprimeMatriz(Matriz* mat) {
    int nLin = recuperaNLinhas(mat);
    int nCol = recuperaNColunas(mat);

    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            if (j != 0) printf(" ");
            printf("%d", recuperaElemento(mat, i, j));
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat) {
    free(mat->inicio);
    free(mat);
}
