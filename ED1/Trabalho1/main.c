#include <stdio.h>
#include <string.h>

void inserePagina();
void retiraPagina();
void insereEditor();
void insereContribuicao();
void insereLink();
void retiraLink();
void caminho();
void imprimePagina();
void imprimeWiked();

int main(int argc, char* argv[]) {
    char comando[20];

    FILE* arq = fopen(argv[1], "r");
    if (arq == NULL) {
        printf("Arquivo invalido.\n");
        return 0;
    }

    do {
        fscanf(arq, "%s", comando);

        if (!strcmp(comando, "FIM"))
            break;

        if (!strcmp(comando, "INSEREPAGINA"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "RETIRAPAGINA"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "INSEREEDITOR"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "INSERECONTRIBUICAO"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "INSERELINK"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "RETIRALINK"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "CAMINHO"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "IMPRIMEPAGINA"))
            printf("%s\n", comando);
        else if (!strcmp(comando, "IMPRIMEWIKED"))
            printf("%s\n", comando);

    } while (strcmp(comando, "FIM"));

    fclose(arq);

    return 0;
}