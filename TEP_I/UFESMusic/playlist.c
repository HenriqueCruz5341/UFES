#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

struct playlist
{
    int idPlaylist;
    int privacidade; // Publica = 0, Privada = 1, Compartilhada = 2
    int contribuintes[2];
    int midia[50];
};

Playlist* inicializaPlaylist(int privacidade, Usuario* usuario, Midia* midia){

}

void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade){

}

void modificaContribuintes(Playlist* playlist, Usuario* nContribuintes){

}

void modificaMidiaPlaylst(Playlist* playlist, Midia* nMidia){

}

int pegaPrivacidadePlaylist(Playlist* playlist){

}

Usuario* pegaContribuintesPlaylist(Playlist* playlist){

}

Midia* pegaMidiaPlaylist(Playlist* playlist){

}

void imprimePlaylist(Playlist* playlist){

}

void destroiPlaylist(Playlist* playlist){

}