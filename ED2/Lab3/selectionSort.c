#include "item.h"

void sort(Item* a, int lo, int hi) {
    int menor, posMenor, aux;

    for (int i = lo; i <= hi; i++) {
        menor = a[i];
        posMenor = i;
        for (int j = i + 1; j <= hi; j++) {
            if (a[j] < menor) {
                menor = a[j];
                posMenor = j;
            }
        }
        aux = a[i];
        a[i] = menor;
        a[posMenor] = aux;
    }
}