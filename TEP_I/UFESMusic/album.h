#ifndef ALBUM_H
#define ALBUM_H
#include "midia.h"

typedef struct album Album;

Album* inicializaAlbum(char* nome, char participantes[][50], char* dataLancamento);

void modificaNomeAlbum(Album* album, char* nNome);

void modificaParticipantesAlbum(Album* album, char** nParticipantes);

void modificaDataLancamentoAlbum(Album* album, char* nDataLancamento);

void modificaQtdMidias(Album* album, int nQtdMidias);

char* pegaNomeAlbum(Album* album);

void pegaParticipantesAlbum(Album* album, char* participantes[50]);

char* pegaDataLancamentoAlbum(Album* album);

int pegaQtdMidiasAlbum(Album* album);

int pegaIdAlbum(Album* album);

Midia* pegaMidiaAlbum(Album* album);

void imprimeAlbum(Album* album);

void destroiAlbum(Album* album);

int listarTodosAlbuns();

Album* buscarAlbum();

void salvarAlbumArquivo(Album* album);

int quantidadeAlbunsCadastrados();

void adicionarMidiasAlbum(Album* album, Midia* midia);

void atualizarArquivoAlbuns(Album* listaAlbuns);

#endif /* ALBUM_H */

