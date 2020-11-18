#include <stdio.h>

#include "Fila.h"

int main() {
    Fila* fila = inicializaFila();
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    insereFila(fila, &num[0]);
    insereFila(fila, &num[1]);
    insereFila(fila, &num[2]);
    insereFila(fila, &num[3]);
    insereFila(fila, &num[4]);

    printf("Imprimindo Fila:\n");
    imprimeFila(fila);

    insereFila(fila, &num[6]);
    insereFila(fila, &num[7]);
    insereFila(fila, &num[8]);
    insereFila(fila, &num[9]);

    printf("Imprimindo Fila:\n");
    imprimeFila(fila);

    insereFila(fila, &num[5]);

    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);

    printf("Imprimindo Fila:\n");
    imprimeFila(fila);

    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);
    retiraFila(fila);

    printf("Imprimindo Fila:\n");
    imprimeFila(fila);

    insereFila(fila, &num[0]);
    insereFila(fila, &num[1]);

    printf("Imprimindo Fila:\n");
    imprimeFila(fila);

    destroiFila(fila);
    return 0;
}