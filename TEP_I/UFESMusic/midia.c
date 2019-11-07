#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midia.h"
#include "album.h"

struct midia
{
    int idMidia;
    char nome[50];
    int tipo; // Musica = 0, Video = 1
    char compositores[3][50];
    char artistas[3][50];
    char genero[15];
    char gravadora[15];
    char duracao[10];
<<<<<<< HEAD
};

Midia* inicializaMidia(char* nome, int tipo, char compositores[][50], char artistas[][50], char* genero, char* gravadora, char* duracao){
=======
    int idAlbum;
};

Midia* inicializaMidia(char* nome, int tipo, char compositores[][50], char artistas[][50], char* genero, char* gravadora, char* duracao, int idAlbum){
>>>>>>> a3c688d9e3d629856891e9068f08b0b349eb3bde
    Midia* midia = (Midia*) malloc(sizeof(Midia));

    if (midia == NULL)
    {
        printf("Erro ao adicionar nova midia!");
        getchar();
        scanf("%*c");
    }

    midia->idMidia = quantidadeMidiasCadastradas()+1;
    strcpy(midia->nome, nome);
    midia->tipo = tipo;
    for (int i = 0; i < 3; i++)
    {
        strcpy(midia->compositores[i], compositores[i]);
        strcpy(midia->artistas[i], artistas[i]);
    }
    strcpy(midia->genero, genero);
    strcpy(midia->gravadora, gravadora);
    strcpy(midia->duracao, duracao);
<<<<<<< HEAD
=======
    midia->idAlbum = idAlbum;
>>>>>>> a3c688d9e3d629856891e9068f08b0b349eb3bde

    return midia;
}

Midia* alocarMidia(Midia* midia, int qtd){
    return (Midia*) malloc(sizeof(Midia) * qtd);
}

void colocarMidiaPosicao(Midia* midiaPrinc, Midia* midia, int pos){
    midiaPrinc = (Midia*) malloc(sizeof(Midia)*20);

    midiaPrinc[pos] = *midia;
}


void modificaNomeMidia(Midia* midia, char* nNome){
    strcpy(midia->nome, nNome);
}

void modificaTipoMidia(Midia* midia, int nTipo){

}

void modificaCompositoresMidia(Midia* midia, char* nCompositor){

}

void modificaArtistasMidia(Midia* midia, char* nArtista){

}

void modificaGeneroMidia(Midia* midia, char* nGenero){

}

void modificaGravadoraMidia(Midia* midia, char* nGravadora){

}

void modificaDuracaoMidia(Midia* midia, char* nDuracao){

}

char* pegaNomeMidia(Midia* midia){
    return midia->nome;
}

int pegaTipoMidia(Midia* midia){
    return midia->tipo;
}

char** pegaCompositoresMidia(Midia* midia){
    //return midia->compositores;
}

char** pegaArtistasMidia(Midia* midia){
    //return midia->artistas;
}

char* pegaGeneroMidia(Midia* midia){
    return midia->genero;
}

char* pegaGravadoraMidia(Midia* midia){
    return midia->gravadora;
}

char* pegaDuracaoMidia(Midia* midia){
    return midia->duracao;
}

<<<<<<< HEAD
=======

>>>>>>> a3c688d9e3d629856891e9068f08b0b349eb3bde
int pegaIdMidia(Midia* midia){
    return midia->idMidia;
}

int pegaAlbumMidia(Midia *midia){
    return midia->idAlbum;
}

void imprimeMidia(Midia* midia){
    printf("\nID: %d", pegaIdMidia(midia));
    printf("\nNome: %s", pegaNomeMidia(midia));
    printf("\nDuracao: %s", pegaDuracaoMidia(midia));
    printf("\nGenero: %s", pegaGeneroMidia(midia));
    printf("\nAlbum: %s", pegaNomeAlbum(buscarAlbum(pegaAlbumMidia(midia))));
}

void destroiMidia(Midia* midia){

}

void atualizaArquivoMidias(Midia* midia){
    FILE *arqMidia;
    int i = 0;

    if ((arqMidia = fopen("midias.dat", "wb")) == NULL)
    {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
        return;
    }

    /*while ((midia+i)->nome != '\0')
    {
        i++;
    }*/
    
    

    if (fwrite(midia, sizeof(Midia), i, arqMidia) == i)
    {
        printf("\nArquivo de midias atualizado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }
    
    fclose(arqMidia);
}

int listarTodasMidias(){
    Midia* midia = (Midia*) malloc(sizeof(Midia));
    int i = 0;

    if (midia == NULL)
    {
        printf("\nErro ao alocar espaco para midia!");
        getchar();
        scanf("%*c");
        return 0;
    }
    
    FILE *arqMidia;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL)
    {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
        return 0;
    }
    
    fread(midia, sizeof(Midia), 1, arqMidia);
    do
    {
        imprimeMidia(midia);
        printf("\n----------");
        fread(midia, sizeof(Midia), 1, arqMidia);
    }while(!feof(arqMidia));

    fclose(arqMidia);
    return 1;
}

Midia* buscarMidia(int indice){
    indice--;
    Midia *midia = (Midia*) malloc(sizeof(Midia)*50);

    int i = 0;

    if (midia == NULL)
    {
        printf("\nErro ao alocar espaco para midia!");
        getchar();
        scanf("%*c");
    }
    
    FILE *arqMidia;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL)
    {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
    }
    
    while (fread(midia+i, sizeof(Midia), 1, arqMidia) == 1 && i != indice)
    {
        i++;
    }

    fclose(arqMidia);

    return midia+i;
}

int quantidadeMidiasCadastradas(){
    Midia* midia = (Midia*) malloc(sizeof(Midia) * 50);
    int i = 0;

    if (midia == NULL)
    {
        printf("\nErro ao alocar espaco para midia!");
        getchar();
        scanf("%*c");
        return 0;
    }
    
    FILE *arqMidia;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL)
    {
        return 0;
    }
       
    while (fread(midia+i, sizeof(Midia), 1, arqMidia) == 1)
    {
        i++;
    }

    fclose(arqMidia);

    return i;

}

void salvarMidiaArquivo(Midia* midia){
    FILE* arqMidias;

    if ((arqMidias = fopen("midias.dat", "ab")) == NULL)
    {
        printf("\nErro ao abrir arquivo de midias!");
        getchar();
        scanf("%*c");
    }

    if (fwrite(midia, sizeof(Midia), 1, arqMidias) == 1)
    {
        printf("\nNova midia adicionada com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }
    
    fclose(arqMidias);
}