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

void quick_sort(Item *a, int lo, int hi) {
    stack_init();
    push2(lo, hi);
    while (!stack_empty()) {
        lo = pop();
        hi = pop();
        if (hi <= lo) continue;  // Could add cutoff here.
        int i = partition(a, lo, hi);
        if (i - lo > hi - i) {  // Test the size of sub-arrays.
            push2(lo, i - 1);   // Push the larger one.
            push2(i + 1, hi);   // Sort the smaller one first.
        } else {
            push2(i + 1, hi);
            push2(lo, i - 1);
        }
    }
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}