#ifndef MIDIA_H
#define MIDIA_H

typedef struct midia Midia;

Midia* inicializaMidia(char* nome, int tipo, char compositores[][50], 
    char artistas[][50], char* genero, char* gravadora, char* duracao, int idAlbum);

Midia* alocarMidia(int qtd);

void modificaNomeMidia(Midia* midia, char* nNome);

void modificaTipoMidia(Midia* midia, int nTipo);

void modificaCompositoresMidia(Midia* midia, char* nCompositor, int pos);

void modificaArtistasMidia(Midia* midia, char* nArtista, int pos);

void modificaGeneroMidia(Midia* midia, char* nGenero);

void modificaGravadoraMidia(Midia* midia, char* nGravadora);

void modificaDuracaoMidia(Midia* midia, char* nDuracao);

char* pegaNomeMidia(Midia* midia);

int pegaTipoMidia(Midia* midia);

char* pegaCompositoresMidia(Midia* midia, int pos);

char* pegaArtistasMidia(Midia* midia, int pos);

char* pegaGeneroMidia(Midia* midia);

char* pegaGravadoraMidia(Midia* midia);

char* pegaDuracaoMidia(Midia* midia);

int pegaIdMidia(Midia* midia);

int pegaAlbumMidia(Midia *midia);

void imprimeMidia(Midia* midia);

void destroiMidia(Midia* midia);

int listarTodasMidias();

Midia* buscarMidia(int idMidia);

void salvarMidiaArquivo(Midia* midia);

int quantidadeMidiasCadastradas();

void atualizarArquivoMidias(Midia* midia);

void excluirMidiaArquivo(Midia* midia, int excluindoAlbum);

int pegaUltimoIdMidiaCadastrado();

void listarMidiasFiltro(int tipoFiltro, char* string, int numero);
/* tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - tipo, 3 - compositor, etc...
string, serve para receber uma string, caso queira pesquisar pelo nome da midia
numero, serve para receber um numero, caso queira pesquisar pelo tipo da midia
*/ 

#endif /* MIDIA_H */

