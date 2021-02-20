#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BST.h"

int main() {
    srand(time(NULL));
    BST* bst = bstCria();

    for (int i = 0; i < 1000000; i++) {
        int r = rand();
        bst = bstInsere(bst, r);
    }

    int altura = bstAltura(bst);
    printf("%d", altura);
    bstImprime(bst);

    bstLibera(bst);
    return 0;
}