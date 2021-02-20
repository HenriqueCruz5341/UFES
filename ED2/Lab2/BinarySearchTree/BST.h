#ifndef BST_H
#define BST_H

typedef struct bst BST;

BST* bstCria(void);

void bstImprime(BST* a);

BST* bstBusca(BST* a, int chave);

BST* bstInsere(BST* a, int chave);

BST* bstRetira(BST* a, int chave);

int bstAltura(BST* a);

void bstImprime(BST* a);

BST* bstLibera(BST* a);

#endif