#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "usuario.h"

struct playlist
{
    char nome[50];
    int idPlaylist;
    int privacidade; // Publica = 0, Privada = 1, Compartilhada = 2
    int qtdMidias;
    int contribuintes[2]; // a primeira posicao sera o dono, a segunda sera com quem ela esta sendo compartilhada
    int midias[50];
};

Playlist* inicializaPlaylist(char* nome, int privacidade, int* contribuintes){
    Playlist* playlist = alocarPlaylist(1);

    playlist->idPlaylist = pegaUltimoIdPlaylistCadastrada() + 1;
    strcpy(playlist->nome, nome);
    playlist->privacidade = privacidade;
    playlist->contribuintes[0] = contribuintes[0];
    playlist->contribuintes[1] = contribuintes[1];
    playlist->qtdMidias = 0;
    for (int i = 0; i < 50; i++)
    {
        playlist->midias[i] = 0;
    }
    
    return playlist;
}

Playlist* alocarPlaylist(int qtd){
    return (Playlist*) malloc(sizeof(Playlist) * qtd);
}

void modificaNomePlaylist(Playlist* playlist, char* nNome){
    strcpy(playlist->nome, nNome);
}

void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade){
    playlist->privacidade = nPrivacidade;
}

void modificaContribuintes(Playlist* playlist, int* nContribuintes){
    for (int i = 0; i < 2; i++)
        playlist->contribuintes[i] = nContribuintes[i];
}

void modificaMidiaPlaylst(Playlist* playlist, int* nMidia){
    for (int i = 0; i < 2; i++)
        playlist->midias[i] = nMidia[i];
}

void modificaQtdMidiasPlaylist(Playlist* playlist, int nQtdMidias){
    playlist->qtdMidias = nQtdMidias;
}

int pegaIdPlaylist(Playlist* playlist){
    return playlist->idPlaylist;
}

char* pegaNomePlaylist(Playlist* playlist){
    return playlist->nome;
}

int pegaPrivacidadePlaylist(Playlist* playlist){
    return playlist->privacidade;
}

int* pegaContribuintesPlaylist(Playlist* playlist){
    return playlist->contribuintes;
}

int* pegaMidiaPlaylist(Playlist* playlist){
    return playlist->midias;
}

int pegaQtdMidiasPlaylist(Playlist* playlist){
    return playlist->qtdMidias;
}

void imprimePlaylist(Playlist* playlist){
    int privacidade = pegaPrivacidadePlaylist(playlist);
    printf("\nID: %d", pegaIdPlaylist(playlist));
    printf("\nNome: %s", pegaNomePlaylist(playlist));
    printf("\nDono: %s", pegaNomeUsuario(buscarUsuario(playlist->contribuintes[0])));
    printf("\nQtd midias: %d", pegaQtdMidiasPlaylist(playlist));
    if (!privacidade)           printf("\nPrivacidade: Publica");
    else if(privacidade == 1)   printf("\nPrivacidade: Privada");
    else                        printf("\nPrivacidade: Compartilhada");
}

void destroiPlaylist(Playlist* playlist){
    if (playlist)
        free(playlist);
}

int pegaUltimoIdPlaylistCadastrada(){
    Playlist* playlist = alocarPlaylist(1);
    int ultimoId;
    FILE* arqPlaylist;

    if ((arqPlaylist = fopen("playlists.dat", "rb")) == NULL)
        return 0;
    
    while (fread(playlist, sizeof(Playlist), 1, arqPlaylist) == 1);

    ultimoId = pegaIdPlaylist(playlist);
    destroiPlaylist(playlist);
    fclose(arqPlaylist);
    return ultimoId;
}

void salvarPlaylistArquivo(Playlist* playlist){
    FILE* arqPlaylist;

    if ((arqPlaylist = fopen("playlists.dat", "ab")) == NULL)
    {
        printf("\nErro ao abrir arquivo de playlist!");
        getchar();
        scanf("%*c");
        return;
    }

    if (fwrite(playlist, sizeof(Playlist), 1, arqPlaylist) == 1)
    {
        printf("\nNova playlist criada com sucesso!");
        printf("\nPressione ENTER para continuar.");
        getchar();
        scanf("%*c");
    }

    fclose(arqPlaylist);
}