#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "usuario.h"
//#include "sistema.h"

struct playlist
{
    char nome[50];
    int idPlaylist;
    int privacidade; // Individual = 0, Compartilhada = 1
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
    Playlist* p = (Playlist*) malloc(sizeof(Playlist) * qtd);
    if (p == NULL)
    {
        printf("\nNao foi possivel alocar espaco para playlist!");
        getchar();
    }
    return p;
}

void modificaNomePlaylist(Playlist* playlist, char* nNome){
    strcpy(playlist->nome, nNome);
}

void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade){
    playlist->privacidade = nPrivacidade;
}

void modificaContribuintesPlaylist(Playlist* playlist, int nContribuintes){
    playlist->contribuintes[1] = nContribuintes;
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
    printf("\nDono: %s", pegaNomeUsuario(buscarUsuario(pegaContribuintesPlaylist(playlist)[0])));
    if (pegaContribuintesPlaylist(playlist)[1] != 0) 
    printf("\nContribuinte: %s", pegaNomeUsuario(buscarUsuario(pegaContribuintesPlaylist(playlist)[1])));
    printf("\nQtd midias: %d", pegaQtdMidiasPlaylist(playlist));
    if (!privacidade)           printf("\nPrivacidade: Publica");
    else                        printf("\nPrivacidade: Individual");
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

Playlist* buscarPlaylist(int idPlaylist){
    Playlist* playlist = alocarPlaylist(1);
    FILE* arqPlaylist;

    if ((arqPlaylist = fopen("playlists.dat", "rb")) == NULL)
    {
        printf("\nErro ao abrir arquivo de playlist!");
        getchar();
        scanf("%*c");
        return NULL;
    }

    while (fread(playlist, sizeof(Playlist), 1, arqPlaylist) == 1 && pegaIdPlaylist(playlist) != idPlaylist);
    
    fclose(arqPlaylist);

    return playlist;

}

int listarTodasPlaylists(){
    Playlist* playlist = alocarPlaylist(1);
    FILE* arqPlaylist;

    if ((arqPlaylist = fopen("playlists.dat", "rb")) == NULL)
    {
        printf("\nErro ao abrir arquivo de playlist!");
        getchar();
        scanf("%*c");
        return 0;
    }

    while (fread(playlist, sizeof(Playlist), 1, arqPlaylist) == 1){
        imprimePlaylist(playlist);
        printf("\n----------");
    }
    
    destroiPlaylist(playlist);
    fclose(arqPlaylist);

    return 1;
}

void atualizarArquivoPlaylists(Playlist* playlist){
    int i = 0;
    Playlist* playlistAux = alocarPlaylist(1);

    FILE* arqPlaylist;

    if ((arqPlaylist = fopen("playlists.dat", "r+b")) == NULL) {
        printf("\nErro ao abrir arquivo de playlists!");
        getchar();
        scanf("%*c");
        return;
    }

    while (fread(playlistAux, sizeof (Playlist), 1, arqPlaylist) == 1 && pegaIdPlaylist(playlistAux) != pegaIdPlaylist(playlist)) {
        i++;
    }

    fseek(arqPlaylist, i * sizeof (Playlist), SEEK_SET);

    if ((fwrite(playlist, sizeof (Playlist), 1, arqPlaylist)) == 1) {
        printf("\nPlaylist atualizado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    destroiPlaylist(playlistAux);
    fclose(arqPlaylist);
}

void adicionarMidiaPlaylist(Playlist* playlist, Midia* midia){
    int *midiasPlaylist = pegaMidiaPlaylist(playlist);
    int i = 0, idMidia = pegaIdMidia(midia);

    while (midiasPlaylist[i] != 0){
        if (idMidia == midiasPlaylist[i])
        {
            printf("\nA midia ja esta nesta playlist!");
            printf("\nPressione ENTER para continuar.");
            getchar();
            return;
        }
        i++;
    }
    modificaQtdMidiasPlaylist(playlist, pegaQtdMidiasPlaylist(playlist) + 1);
    midiasPlaylist[i] = idMidia;
}

void removerMidiaPlaylist(Playlist* playlist, Midia* midia){
    int *midiasPlaylist = pegaMidiaPlaylist(playlist);
    int pos, idMidia = pegaIdMidia(midia), excluiu = 0, qtdMidiasPlaylist = pegaQtdMidiasPlaylist(playlist);

    for (pos = 0; pos < qtdMidiasPlaylist; pos++) {
        if (excluiu) {
            midiasPlaylist[pos - 1] = midiasPlaylist[pos];
            midiasPlaylist[pos] = 0;
        }
        if (midiasPlaylist[pos] == idMidia) {
            midiasPlaylist[pos] = 0;
            excluiu = 1;
        }
    }

    modificaQtdMidiasPlaylist(playlist, pegaQtdMidiasPlaylist(playlist) - 1);
}

void listarMidiasPlaylist(Playlist* playlist){
    int qtdMidias = pegaQtdMidiasPlaylist(playlist);
    Midia* midia = alocarMidia(1);

    for (int i = 0; i < qtdMidias; i++) {
        midia = buscarMidia(pegaMidiaPlaylist(playlist)[i]);
        imprimeMidia(midia);
        printf("\n-----------");
    }
}

void trocarPosicaoMidiaPlaylist(Playlist* playlist, Midia* midia, int pos){
    int* midias = pegaMidiaPlaylist(playlist);
    int qtdMidias = pegaQtdMidiasPlaylist(playlist), posMidia = 0, idMidia = pegaIdMidia(midia);
    
    if (pos > qtdMidias) pos = qtdMidias;

    while(midias[posMidia] != idMidia) posMidia++;
    
    if (qtdMidias == pos)
    {
        for (int i = posMidia+1; i < qtdMidias; i++)
        {
            midias[i-1] = midias[i];
        }
        midias[qtdMidias-1] = idMidia;
    }else
    {
        for (int i = posMidia-1; i >= pos-1; i--)
        {
            midias[i+1] = midias[i];
        }
        midias[pos-1] = idMidia;
    }
}

int quantidadePlaylistsCadastradas(){
    Playlist* playlist = alocarPlaylist(1);
    FILE* arqPlaylists;
    int i = 0;

    if ((arqPlaylists = fopen("playlists.dat", "rb")) == NULL)
    {
        return 0;
    }

    while(fread(playlist, sizeof(Playlist), 1, arqPlaylists) == 1) i++;
    
    fclose(arqPlaylists);
    destroiPlaylist(playlist);

    return i;
}


void excluirPlaylistArquivo(Playlist* playlist){
    FILE* arqPlaylist;
    Playlist* playlistAux = alocarPlaylist(1);
    int qtd = quantidadePlaylistsCadastradas(), removeu = 0, idPlaylistExcluida = pegaIdPlaylist(playlist);
    Playlist* listaPlaylists = alocarPlaylist(qtd);

    if ((arqPlaylist = fopen("playlists.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de playlist!");
        getchar();
        scanf("%*c");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fread(playlistAux, sizeof (Playlist), 1, arqPlaylist);
        if (pegaIdPlaylist(playlistAux) == pegaIdPlaylist(playlist)) {
            removeu = 1;
        } else if (removeu) {
            listaPlaylists[i - 1] = *playlistAux;
        } else {
            listaPlaylists[i] = *playlistAux;
        }
    }

    destroiPlaylist(playlistAux);
    fclose(arqPlaylist);

    if ((arqPlaylist = fopen("playlists.dat", "wb")) == NULL) {
        printf("\nErro ao abrir arquivo de playlist!");
        getchar();
        scanf("%*c");
        return;
    }

    if (qtd > 1) fwrite(listaPlaylists, sizeof (Playlist), qtd - 1, arqPlaylist);
    fclose(arqPlaylist);
    destroiPlaylist(listaPlaylists);
    removerPlaylistTodosUsuario(idPlaylistExcluida);
}

void listarPlaylistsFiltro(int tipoFiltro, char* string){
    FILE* arqPlaylists;
    Playlist* playlist = alocarPlaylist(1);
    char* stringAux = NULL;

    if ((arqPlaylists = fopen("playlists.dat", "rb")) == NULL) {
        printf("\nAinda nao possuem playlists cadastradas!");
        getchar();
        scanf("%*c");
        return;
    }

    printf("\nListando playlists encontradas...");

    switch (tipoFiltro) {
        case 1:
            while (fread(playlist, sizeof (Playlist), 1, arqPlaylists) == 1) {
                stringAux = strstr(pegaNomePlaylist(playlist), string);
                if (stringAux) {
                    imprimePlaylist(playlist);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;

        case 2:
            while (fread(playlist, sizeof (Playlist), 1, arqPlaylists) == 1) {
                stringAux = strstr(pegaNomeUsuario(buscarUsuario(pegaContribuintesPlaylist(playlist)[0])), string);
                if (stringAux) {
                    imprimePlaylist(playlist);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;
    }

    fclose(arqPlaylists);
    destroiPlaylist(playlist);
}