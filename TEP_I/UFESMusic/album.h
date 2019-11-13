#ifndef ALBUM_H
#define ALBUM_H
#include "midia.h"

typedef struct album Album;

Album* inicializaAlbum(char* nome, char participantes[][50], char* dataLancamento);

Album* alocarAlbum(int qtd);

void modificaNomeAlbum(Album* album, char* nNome);

void modificaParticipantesAlbum(Album* album, char** nParticipantes);

void modificaDataLancamentoAlbum(Album* album, char* nDataLancamento);

void modificaMidiasAlbum(Album* album, int* nMidias);

void modificaQtdMidias(Album* album, int nQtdMidias);

char* pegaNomeAlbum(Album* album);

void pegaParticipantesAlbum(Album* album, char* participantes[50]);

char* pegaDataLancamentoAlbum(Album* album);

int pegaQtdMidiasAlbum(Album* album);

int pegaIdAlbum(Album* album);

int* pegaMidiaAlbum(Album* album);

void imprimeAlbum(Album* album);

void destroiAlbum(Album* album);

int listarTodosAlbuns();

Album* buscarAlbum(int idAlbum);

void salvarAlbumArquivo(Album* album);

int quantidadeAlbunsCadastrados();

void adicionarMidiasAlbum(Album* album, Midia* midia);

void removeMidiaAlbum(Album* album, Midia* midia);

void atualizarArquivoAlbuns(Album* album);

void imprimirMidiasAlbum(Album* album);

void excluirAlbumArquivo(Album* album);

int pegaUltimoIdAlbumCadastrado();

void listarAlbunsFiltro(int tipoFiltro, char* string, int numero);
/* tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - tipo, 3 - compositor, etc...
string, serve para receber uma string, caso queira pesquisar pelo nome do album
numero, serve para receber um numero, caso queira pesquisar pelo tipo do album
*/ 

#endif /* ALBUM_H */

