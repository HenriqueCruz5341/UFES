#include<stdio.h>


void ler (int *x, int *y, int *z){
    scanf("%d %d %d", x, y, z);
}

void ordenar (int *menor, int *intermediario, int *maior){
    int aux;
    if(*menor <= *intermediario && *intermediario >= *maior && *menor <= *maior){
        aux = *intermediario;
        *intermediario = *maior;
        *maior = aux;
    }else if(*menor >= *intermediario && *intermediario <= *maior && *menor <= *maior){
        aux = *intermediario;
        *intermediario = *menor;
        *menor = aux;
    }else if(*menor >= *maior && *menor <= *intermediario && *intermediario >= *maior){
        aux = *menor;
        *menor = *maior;
        *maior = aux;
        aux = *intermediario;
        *intermediario = *maior;
        *maior = aux;
    }else if(*menor >= *maior && *menor >= *intermediario && *intermediario <= *maior){
        aux = *menor;
        *menor = *intermediario;
        *intermediario = aux;
        aux = *intermediario;
        *intermediario = *maior;
        *maior = aux;
    }else if(*menor >= *maior && *menor >= *intermediario && *intermediario >= *maior){
        aux = *menor;
        *menor = *maior;
        *maior = aux;
    }
}

int par (int n){
    if(n%2){
        return 0;
    }
    return 1;
}

