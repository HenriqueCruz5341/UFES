#include <stdio.h>

#include "TadPilhasDuplas.h"

int main() {
    PilhasDuplas* pd = inicializaPilhas();
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    pushPilha1(pd, &num[0]);
    pushPilha1(pd, &num[1]);
    pushPilha1(pd, &num[2]);
    pushPilha1(pd, &num[3]);
    pushPilha1(pd, &num[4]);

    printf("Imprimindo Pilha1:\n");
    imprimePilha1(pd);

    pushPilha2(pd, &num[9]);
    pushPilha2(pd, &num[8]);
    pushPilha2(pd, &num[7]);
    pushPilha2(pd, &num[6]);

    printf("Imprimindo Pilha2:\n");
    imprimePilha2(pd);

    pushPilha1(pd, &num[5]);  // não será possivel pois a pilha estará cheia
    pushPilha2(pd, &num[5]);  // não será possivel pois a pilha estará cheia

    popPilha1(pd);
    popPilha1(pd);
    popPilha1(pd);

    printf("Imprimindo Pilha1:\n");
    imprimePilha1(pd);

    popPilha2(pd);
    popPilha2(pd);
    popPilha2(pd);
    popPilha2(pd);
    popPilha2(pd);  //não será possível pois está vazia

    printf("Imprimindo Pilha2:\n");
    imprimePilha2(pd);

    destroiPilhas(pd);

    return 0;
}