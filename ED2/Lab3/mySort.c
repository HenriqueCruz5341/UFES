#include "item.h"

void sort(Item* a, int lo, int hi) {
    for (int i = lo; i <= hi; i++) {
        for (int j = lo; j <= hi; j++) {
            if (a[i] != a[j]) {
                compexch(a[j], a[i]);
            }
        }
    }
}