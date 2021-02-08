#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ponto
{
    int x;
    int y;
}Ponto;

typedef struct retangulo
{
    char nome[15];
    int vertices[4];
}Retangulo;

Ponto* cadastrarPonto();
void cadastrarRetangulo();
void imprimirPonto(Ponto* ponto);
void imprimirRetangulos();

int main(){
    int op;

    do
    {
        printf("\n 1 - cadastrar ponto;");
        printf("\n 2 - cadastrar Retangulo.");
        printf("\n 3 - imprimir pontos.");
        printf("\n 4 - imprimir Retangulos.");
        printf("\n Digite a opcao desejada: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            //cadastrarPonto();    
        break;

        case 2:
            cadastrarRetangulo();
        break;

        case 3:
            //imprimirPonto();
        break;

        case 4:
            imprimirRetangulos();
        break;
        
        
        }
    } while (op);
    
    return 0;
}

Ponto* cadastrarPonto(){
    Ponto* ponto = (Ponto*) malloc(sizeof(Ponto));
    int x, y;

    printf("\nDigite a coordenada X: ");
    scanf("%d", &x);
    printf("\nDigite a coordenada y: ");
    scanf("%d", &y);

    ponto->x = x;
    ponto->y = y;

    FILE* arquivo = fopen("teste.dat", "ab");

    fwrite(ponto, sizeof(Ponto), 1, arquivo);

    fclose(arquivo);

    return ponto;
}

void cadastrarRetangulo(){
    Retangulo* retangulo = (Retangulo*) malloc(sizeof(Retangulo));
    char nome[15];

    printf("\nDigite o nome do retangulo: ");
    scanf("%s", nome);

    strcpy(retangulo->nome, nome);

    
    for(int i = 0; i < 4; i++){
        printf("\nDigite %d: ", i);
        scanf("%d", &(retangulo->vertices[i]));
    }

    FILE* arquivo = fopen("teste.dat", "ab");

    fwrite(retangulo, sizeof(Retangulo), 1, arquivo);

    fclose(arquivo);
}

void imprimirRetangulos(){
    FILE* arquivo = fopen("teste.dat", "rb");
    int j = 0;
    Retangulo* retangulo = (Retangulo*) malloc(sizeof(Retangulo));
    //Ponto* ponto = (Ponto*) malloc(sizeof(Ponto));



    while (fread(retangulo, sizeof(Retangulo), 1, arquivo) == 1)
    {
        printf("\nNome: %s", retangulo->nome);
        printf("\nPonto 1: %d %d", retangulo->vertices[0], retangulo->vertices[1]);
        printf("\nPonto 2: %d %d", retangulo->vertices[2], retangulo->vertices[3]);
    }
    
    fclose(arquivo);
}

void imprimirPonto(Ponto* ponto){
    printf("\nX: %d", ponto->x);
    printf("\nY: %d", ponto->y);
}