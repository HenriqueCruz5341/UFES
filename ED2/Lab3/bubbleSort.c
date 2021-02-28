#include "item.h"

void sort(Item* a, int lo, int hi) {
    int aux, wall;
    int i, j;

    for (wall = hi; wall >= lo; wall--) {
        for (i = lo + 1, j = lo; i <= hi; i++, j++)
            compexch(a[j], a[i]);
    }
}