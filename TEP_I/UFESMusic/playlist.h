#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "midia.h"

typedef struct playlist Playlist;

Playlist* inicializaPlaylist(char* nome, int privacidade, int* contribuintes);

Playlist* alocarPlaylist(int qtd);

void modificaNomePlaylist(Playlist* playlist, char* nNome);

void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade);

void modificaContribuintesPlaylist(Playlist* playlist, int nContribuintes);

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

Playlist* buscarPlaylist(int idPlaylist);

int listarTodasPlaylists();

void atualizarArquivoPlaylists(Playlist* playlist);

void adicionarMidiaPlaylist(Playlist* playlist, Midia* midia);

void removerMidiaPlaylist(Playlist* playlist, Midia* midia);

void listarMidiasPlaylist(Playlist* playlist);

void trocarPosicaoMidiaPlaylist(Playlist* playlist, Midia* midia, int pos);

void excluirPlaylistArquivo(Playlist* playlist);

int quantidadePlaylistsCadastradas();

void listarPlaylistsFiltro(int tipoFiltro, char* string);
/* tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - nome dono
string, serve para receber uma string, caso queira pesquisar pelo nome da playlist ou dono
*/ 

void removerMidiaTodasPLaylists(int idMidia);

#endif /* PLAYLIST_H */

