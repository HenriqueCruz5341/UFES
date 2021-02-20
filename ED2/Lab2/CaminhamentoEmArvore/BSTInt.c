#include "BSTInt.h"

#include <stdio.h>

void imprime(void* item) {
    int* aux = item;
    // printf("%d, ", *aux);
}

void imprimePreOrder(BST* a) {
    bstVisitPreOrder(a, imprime);
}

void imprimeInOrder(BST* a) {
    bstVisitInOrder(a, imprime);
}

void imprimePosOrder(BST* a) {
    bstVisitPosOrder(a, imprime);
}
