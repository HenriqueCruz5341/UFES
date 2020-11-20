#include <stdio.h>

void imprimeLog(char* mensagem, char* var) {
    FILE* arq = fopen("log.txt", "a");
    if (arq == NULL) {
        printf("Arquivo invalido.\n");
        return;
    }

    if (var)
        fprintf(arq, "%s%s\n", mensagem, var);
    else
        fprintf(arq, "%s\n", mensagem);

    fclose(arq);
}