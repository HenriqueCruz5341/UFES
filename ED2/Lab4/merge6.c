#include <stdlib.h>

#include "item.h"

#define SZ2 (sz + sz)
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k];  // Copy array
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {  // Merge
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}

void insert_sort(Item *a, int lo, int hi) {
    int aux;
    int i, j, k;

    for (i = lo + 1; i <= hi; i++) {
        for (j = i - 1, k = i; j >= lo; j--, k--) {
            compexch(a[j], a[i]);
        }
    }
}

/*altere a Versao 5 para implementar o que seria o “cut-off ” na versao bottom-up*/
void sort(Item *a, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = malloc(N * sizeof(Item));
    for (int sz = 1; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N - sz; lo += SZ2) {
            if (hi <= lo + 10 - 1) {
                insert_sort(a, lo, hi);
                break;
            }
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo + sz - 1, MIN(x, y));
        }
    }
    free(aux);
}