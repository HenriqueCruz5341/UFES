#ifndef PLAYLIST_H
#include "usuario.h"
#include "midia.h"
#define PLAYLIST_H

typedef struct playlist Playlist;

Playlist* inicializaPlaylist(int privacidade, Usuario* usuario, Midia* midia);

void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade);

void modificaContribuintes(Playlist* playlist, Usuario* nContribuintes);

void modificaMidiaPlaylst(Playlist* playlist, Midia* nMidia);

int pegaPrivacidadePlaylist(Playlist* playlist);

Usuario* pegaContribuintesPlaylist(Playlist* playlist);

Midia* pegaMidiaPlaylist(Playlist* playlist);

void imprimePlaylist(Playlist* playlist);

void destroiPlaylist(Playlist* playlist);

#endif /* PLAYLIST_H */

