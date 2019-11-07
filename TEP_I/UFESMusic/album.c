#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "midia.h"
#include "playlist.h"

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
    album->midia = alocarMidia(album->midia, 20);

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

Midia* pegaMidiaAlbum(Album* album){
    return album->midia;
}


void imprimeAlbum(Album* album){
    char* participantes[50];
    //pegaParticipantesAlbum(album, participantes);
    
    printf("\nID: %d", pegaIdAlbum(album));
    printf("\nNome: %s", pegaNomeAlbum(album));
    printf("\nQuantidade midias: %d", pegaQtdMidiasAlbum(album));
    printf("\nLancado em: %s", pegaDataLancamentoAlbum(album));
    if(pegaQtdMidiasAlbum(album) != 0){
        imprimeMidia(pegaMidiaAlbum(album));
    }
}

void destroiAlbum(Album* album){

}

int listarTodosAlbuns(){
    Album* album = (Album*) malloc(sizeof(Album) * 50);
    int i = 0;

    if (album == NULL)
    {
        printf("\nErro ao alocar espaco para album!");
        getchar();
        scanf("%*c");
        return 0;
    }
    
    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL)
    {
        printf("\nAinda não existem albuns cadastrados!");
        return 0;
    }

    fread(album, sizeof(Album), 1, arqAlbum);
    do
    {
        imprimeAlbum(album);
        printf("\n----------");
        fread(album, sizeof(Album), 1, arqAlbum);
    }while (!feof(arqAlbum));
    
    fclose(arqAlbum);
    
    return 1;
}

Album* buscarAlbum(int idAlbum){
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

    while (fread(album+i, sizeof(Album), 1, arqAlbum) == 1 && (album+i)->idAlbum != idAlbum)
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

    fread(listaAlbuns+i, sizeof(Album), 1, arqAlbum);
    do
    {
        i++;
        fread(listaAlbuns+i, sizeof(Album), 1, arqAlbum);
    } while (!feof(arqAlbum));

    fclose(arqAlbum);
    i = 0;
    
    while ((listaAlbuns+i)->idAlbum != album->idAlbum)
    {
        i++;
    }

    int pos = pegaQtdMidiasAlbum(listaAlbuns+i);
    colocarMidiaPosicao((listaAlbuns+i)->midia, midia, pos);
    modificaQtdMidias((listaAlbuns+i),pegaQtdMidiasAlbum(listaAlbuns+i)+1);
    atualizarArquivoAlbuns(listaAlbuns+i);
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
    
    fclose(arqAlbum);

    return i;
}

void salvarAlbumArquivo(Album* album){
    FILE* arqAlbuns;

    if ((arqAlbuns = fopen("albuns.dat", "ab")) == NULL)
    {
        printf("\nErro ao abrir arquivo de albuns!");
        getchar();
        scanf("%*c");
    }

    if ((fwrite(album, sizeof(Album), 1, arqAlbuns)) == 1){
        printf("\nAlbum adicionado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    fclose(arqAlbuns);
}

void atualizarArquivoAlbuns(Album* listaAlbuns){
    imprimeAlbum(listaAlbuns);
    int i = 0;
    Album* album = (Album*) malloc(sizeof(Album) * 50);
    
    FILE* arqAlbuns;

    if ((arqAlbuns = fopen("albuns.dat", "r+b")) == NULL)
    {
        printf("\nErro ao abrir arquivo de albuns!");
        getchar();
        scanf("%*c");
    }
    
    while (fread(album+i, sizeof(Album), 1, arqAlbuns) == 1 && pegaIdAlbum(album+i) != pegaIdAlbum(listaAlbuns))
    {
        imprimeAlbum(album+i);
        i++;
    }
    
    fseek(arqAlbuns, i*sizeof(Album), SEEK_SET);
    
    if ((fwrite(listaAlbuns, sizeof(Album), 1, arqAlbuns)) == 1){
        printf("\nAlbum adicionado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }
    
    free(album);
    fclose(arqAlbuns);
}
