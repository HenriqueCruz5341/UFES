#include <stdlib.h>

#include "item.h"

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

/*merge sort top-down recursivo com cut-off para insertion sort. Implemente o
seu codigo de forma que seja facil modificar o valor de cut-off.*/
void merge_sort(Item *a, Item *aux, int lo, int hi) {
    if (hi <= lo + 10 - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi) {
    int n = (hi - lo) + 1;
    Item *aux = malloc(n * sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);
}