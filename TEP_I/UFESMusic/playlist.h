#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

Playlist* inicializaPlaylist(char* nome, int privacidade, int* contribuintes);

Playlist* alocarPlaylist(int qtd);

void modificaNomePlaylist(Playlist* playlist, char* nNome);

void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade);

void modificaContribuintes(Playlist* playlist, int* nContribuintes);

void modificaMidiaPlaylst(Playlist* playlist, int* nMidia);

void modificaQtdMidiasPlaylist(Playlist* playlist, int nQtdMidias);

int pegaIdPlaylist(Playlist* playlist);

char* pegaNomePlaylist(Playlist* playlist);

int pegaPrivacidadePlaylist(Playlist* playlist);

int* pegaContribuintesPlaylist(Playlist* playlist);

int* pegaMidiaPlaylist(Playlist* playlist);

int pegaQtdMidiasPlaylist(Playlist* playlist);

void imprimePlaylist(Playlist* playlist);

void destroiPlaylist(Playlist* playlist);

int pegaUltimoIdPlaylistCadastrada();

void salvarPlaylistArquivo(Playlist* playlist);

#endif /* PLAYLIST_H */

