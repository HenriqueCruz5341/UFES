#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BST.h"
#include "Pilha.h"

int main() {
    clock_t start = clock();
    srand(time(NULL));
    BST* bst = bstCria();

    for (int i = 0; i < 10000000; i++) {
        int r = rand();
        bst = bstInsere(bst, r);
    }

    bstPreOrderTraversal(bst);

    // bstInOrderTraversal(bst);

    // bstPosOrderTraversal(bst);

    bstLibera(bst);

    clock_t end = clock();
    double seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf(" % lf \n", seconds);
    return 0;

    // bst = bstInsere(bst, 6);
    // bst = bstInsere(bst, 2);
    // bst = bstInsere(bst, 1);
    // bst = bstInsere(bst, 4);
    // bst = bstInsere(bst, 3);
    // bst = bstInsere(bst, 5);
    // bst = bstInsere(bst, 7);
    // bst = bstInsere(bst, 9);
    // bst = bstInsere(bst, 8);

    // bstPreOrderTraversal(bst);
    // printf("\n===============\n");
    // bstInOrderTraversal(bst);
    // printf("\n===============\n");
    // bstPosOrderTraversal(bst);
    // printf("\n===============\n");
    // bstLibera(bst);

    return 0;
}
