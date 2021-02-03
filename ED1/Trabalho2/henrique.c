#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arv.h"

int main(int argc, char** argv) {
    char vet[1000];
    float resultado;

    FILE* arq = fopen(argv[1] /*"entrada.txt"*/, "r");
    if (arq == NULL) {
        printf("Arquivo invalido.\n");
        return 0;
    }

    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) {
        printf("Arquivo invalido.\n");
        return 0;
    }

    while (fscanf(arq, "%s", vet) == 1) {
        char* expressao = strdup(vet);

        Arv* arv = arvCria(expressao);

        // Caso queira ver as árvores criadas
        // arvImprime(arv);
        // printf("\n");

        resultado = arvCalculaExpressao(arv);

        fprintf(saida, "%.2f\n", resultado);

        arvLibera(arv);
        free(expressao);
    }

    fclose(arq);
    fclose(saida);

    return 0;
}