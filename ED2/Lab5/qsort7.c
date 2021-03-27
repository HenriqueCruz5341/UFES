#include <stdlib.h>
#include <sys/time.h>

#include "item.h"

void shuffle(Item *a, int N) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand48(usec);

    if (N > 1) {
        size_t i;
        for (i = N - 1; i > 0; i--) {
            size_t j = (unsigned int)(drand48() * (i + 1));
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
}

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

int median_of_3(Item *a, int lo, int hi) {
    int mi = (hi + lo) / 2;
    Item x = a[lo];
    Item y = a[mi];
    Item z = a[hi];
    if (less(x, y)) {
        if (less(y, z)) {
            return mi;
        } else if (less(x, z)) {
            return hi;
        } else
            return lo;
    } else {
        if (less(z, y))
            return mi;
        else if (less(z, x)) {
            return hi;
        } else
            return lo;
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

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j - 1);
    quick_sort(a, j + 1, hi);
}

void sort(Item *a, int lo, int hi) {
    shuffle(a, hi - lo + 1);  // Needed for performance guarantee.
    quick_sort(a, lo, hi);
}