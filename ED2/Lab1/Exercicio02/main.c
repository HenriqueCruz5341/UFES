#include <stdio.h>

#include "ListaCirc.h"

int main() {
    int num = 41;
    int m = 3;
    int removido;

    ListaCirc* listaCirc = inicializaLista();

    populaListaCirc(listaCirc, num);

    while (!existeLider(listaCirc)) {
        removido = removeListaCirc(listaCirc, m);
        printf("%d, ", removido);
    }
    removido = removeListaCirc(listaCirc, m);
    printf("\nLider: %d\n", removido);

    destroiListaCirc(listaCirc);

    return 0;
}
