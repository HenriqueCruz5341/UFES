#include <stdlib.h>

#include "item.h"

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi + 1;
    Item v = a[lo];
    while (1) {
        while (less(a[++i], v))
            if (i == hi) break;
        while (less(v, a[--j]))
            if (j == lo) break;
        if (i >= j) break;
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]);
    return j;
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

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo + 10 - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j - 1);
    quick_sort(a, j + 1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}