#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int VerificaProgressao(int vet[], int tamVet, int dif);

int main(int argc, char** argv) {
    int tam, i, diferenca;

    scanf("%d", &tam);

    int vetor[tam];

    if (tam > 1) {
        for (i = 0; i < tam; i++) {
            scanf("%d", &vetor[i]);
        }

        diferenca = vetor[1] - vetor[0];

        if(VerificaProgressao(vetor, tam, diferenca)){
            printf("RESP:%d", diferenca);
        }else{
            printf("NAO");
        }
        
    } else {
        printf("NAO");
    }


    return 0;
}

int VerificaProgressao(int vet[], int tamVet, int dif) {
    int i, cont = 0;

    for (i = 1; i < tamVet; i++) {
        if ((vet[i] - vet[i-1]) != dif) {
            return 0;
        }
    }
    return 1;

}
