#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

struct playlist
{
    int idPlaylist;
    int privacidade; // Publica = 0, Privada = 1, Compartilhada = 2
    int contribuintes[2]; // a primeira posicao sera o dono, a segunda sera com quem ela esta sendo compartilhada
    int midia[50];
};

Playlist* inicializaPlaylist(int privacidade, Usuario* usuario, Midia* midia){

}

void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade){

}

void modificaContribuintes(Playlist* playlist, int* nContribuintes){

}

void modificaMidiaPlaylst(Playlist* playlist, int* nMidia){

}

int pegaPrivacidadePlaylist(Playlist* playlist){

}

int* pegaContribuintesPlaylist(Playlist* playlist){

}

int* pegaMidiaPlaylist(Playlist* playlist){

}

void imprimePlaylist(Playlist* playlist){

}

void destroiPlaylist(Playlist* playlist){

}