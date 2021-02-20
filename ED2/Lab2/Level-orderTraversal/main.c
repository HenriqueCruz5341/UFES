#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BST.h"
#include "Fila.h"

int main() {
    BST* bst = bstCria();

    bst = bstInsere(bst, 6);
    bst = bstInsere(bst, 2);
    bst = bstInsere(bst, 1);
    bst = bstInsere(bst, 4);
    bst = bstInsere(bst, 3);
    bst = bstInsere(bst, 5);
    bst = bstInsere(bst, 7);
    bst = bstInsere(bst, 9);
    bst = bstInsere(bst, 8);

    bstLevelOrderTraversal(bst);

    bstLibera(bst);

    return 0;
}
