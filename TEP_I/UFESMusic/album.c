#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "midia.h"

struct album
{
    int idAlbum;
    char nome[50];
    char participantes[3][50];
    char dataLancamento[11];
    int qtdMidias;
    Midia* midia;
};

Album* inicializaAlbum(char* nome, char participantes[][50], char* dataLancamento){
    Album* album = (Album*) malloc(sizeof(Album));

    if (album == NULL)
    {
        printf("\nErro ao criar novo album!");
        getchar();
        scanf("%*c");
    }

    album->idAlbum = quantidadeAlbunsCadastrados()+1;
    strcpy(album->nome, nome);
    for (int i = 0; i < 3; i++)
    {
        strcpy(album->participantes[i], participantes[i]);
    }
    strcpy(album->dataLancamento, dataLancamento);
    album->qtdMidias = 0;
    album->midia = (Midia*) malloc((398 + sizeof(Album*)) * 20);

    if (album->midia == NULL)
    {
        printf("\nErro ao alocar espaco para midia!");
        getchar();
        scanf("%*c");
    }
    
    return album;
}

void modificaNomeAlbum(Album* album, char* nNome){

}

void modificaParticipantesAlbum(Album* album, char** nParticipantes){

}

void modificaDataLancamentoAlbum(Album* album, char* nDataLancamento){

}

void modificaQtdMidias(Album* album, int nQtdMidias){
    album->qtdMidias = nQtdMidias;
}


char* pegaNomeAlbum(Album* album){
    return album->nome;
}

void pegaParticipantesAlbum(Album* album, char* participantes[50]){
    for(int i = 0; i < 3; i++){
        strcpy(participantes[i], album->participantes[i]);
    }
}

char* pegaDataLancamentoAlbum(Album* album){
    return album->dataLancamento;
}

int pegaQtdMidiasAlbum(Album* album){
    return album->qtdMidias;
}

int pegaIdAlbum(Album* album){
    return album->idAlbum;
}

void imprimeAlbum(Album* album){
    char* participantes[50];
    //pegaParticipantesAlbum(album, participantes);
    
    printf("\nID: %d", pegaIdAlbum(album));
    printf("\nNome: %s", pegaNomeAlbum(album));
    printf("\nQuantidade midias: %d", pegaQtdMidiasAlbum(album));
    printf("\nLancado em: %s", pegaDataLancamentoAlbum(album));
}

void destroiAlbum(Album* album){

}

void listarTodosAlbum(){
    Album* album = (Album*) malloc(sizeof(Album) * 50);
    int i = 0;

    if (album == NULL)
    {
        printf("\nErro ao alocar espaco para album!");
        getchar();
        scanf("%*c");
    }
    
    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL)
    {
        printf("\nAinda não existem albuns cadastrados!");
        return;
    }

    while (fread(album, sizeof(Album), 1, arqAlbum) == 1){
        fread(album, sizeof(Album), 1, arqAlbum);
        imprimeAlbum(album);
        printf("\n----------");
        i++;
    }
}

Album* buscarAlbum(int indice){
    indice--;
    Album *album = (Album*) malloc(sizeof(Album)*50);

    int i = 0;

    if (album == NULL)
    {
        printf("\nErro ao alocar espaco para album!");
        getchar();
        scanf("%*c");
    }
    
    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL)
    {
        printf("\nErro ao abrir arquivo de album!");
        getchar();
        scanf("%*c");
    }
       
    while (fread(album+i, sizeof(Album), 1, arqAlbum) == 1 && (album+i)->idAlbum == indice)
    {
        i++;
    }

    fclose(arqAlbum);

    return album+i;
}

void adicionarMidiasAlbum(Album* album, Midia* midia){
    Album* listaAlbuns = (Album*) malloc(sizeof(Album) * 50);
    int i = 0;

    if (listaAlbuns == NULL)
    {
        printf("\nErro ao alocar espaco para album!");
        getchar();
        scanf("%*c");
    }
    
    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL)
    {
        printf("\nErro ao abrir arquivo de album!");
        getchar();
        scanf("%*c");
    }
       
    while (fread(listaAlbuns+i, sizeof(Album), 1, arqAlbum) == 1)
    {
        i++;
    }

    fclose(arqAlbum);
    i = 0;

    while (strcmp((listaAlbuns+i)->nome, album->nome))
    {
        i++;
    }

    Midia* midiaAlbum = (listaAlbuns+i)->midia;    

    for (int j = 0; j < pegaQtdMidiasAlbum(listaAlbuns+i); j++)
    {
        //Quero adicionar musica no final na lista de midias do album
        //(midiaAlbum+j) = midia;
    }
    

    midiaAlbum = midia;
}

int quantidadeAlbunsCadastrados(){
    Album* album = (Album*) malloc(sizeof(Album) * 50);
    int i = 0;

    if (album == NULL)
    {
        printf("\nErro ao alocar espaco para album!");
        getchar();
        scanf("%*c");
    }
    
    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL)
    {
        printf("\nAinda não existem albuns cadastrados!");
        return 0;
    }

    while (fread(album, sizeof(Album), 1, arqAlbum) == 1){
        i++;
    }

    return i;
}