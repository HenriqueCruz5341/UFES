#include "item.h"

void sort(Item* a, int lo, int hi) {
    int floor = lo, roof = hi;
    int i, j;

    while (roof >= floor) {
        for (i = floor + 1, j = floor; i <= roof; i++, j++) {
            compexch(a[j], a[i]);
        }
        roof--;
        i--;
        j--;
        for (; j >= floor; i--, j--) {
            compexch(a[j], a[i]);
        }
        floor++;
    }
}
