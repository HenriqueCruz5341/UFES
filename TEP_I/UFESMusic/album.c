#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "midia.h"

struct album {
    int idAlbum;
    char nome[50];
    char participantes[3][50];
    char dataLancamento[11];
    int qtdMidias;
    int midia[20];
};

Album* inicializaAlbum(char* nome, char participantes[][50], char* dataLancamento) {
    Album* album = (Album*) malloc(sizeof (Album));

    if (album == NULL) {
        printf("\nErro ao criar novo album!");
        getchar();
        scanf("%*c");
    }

    album->idAlbum = pegaUltimoIdAlbumCadastrado() + 1;
    strcpy(album->nome, nome);
    for (int i = 0; i < 3; i++) {
        strcpy(album->participantes[i], participantes[i]);
    }
    for (int i = 0; i < 20; i++) {
        album->midia[i] = 0;
    }

    strcpy(album->dataLancamento, dataLancamento);
    album->qtdMidias = 0;

    return album;
}

Album* alocarAlbum(int qtd) {
    return (Album*) malloc(sizeof (Album) * qtd);
}

void modificaNomeAlbum(Album* album, char* nNome) {
    strcpy(album->nome, nNome);
}

void modificaParticipantesAlbum(Album* album, char* nParticipantes, int pos) {
    strcpy(album->participantes[pos], nParticipantes);
}

void modificaDataLancamentoAlbum(Album* album, char* nDataLancamento) {
    strcpy(album->dataLancamento, nDataLancamento);
}

void modificaQtdMidias(Album* album, int nQtdMidias) {
    album->qtdMidias = nQtdMidias;
}

void modificaMidiasAlbum(Album* album, int* nMidias) {
    for (int i = 0; i < 20; i++) {
        album->midia[i] = nMidias[i];
    }
}

char* pegaNomeAlbum(Album* album) {
    return album->nome;
}

char* pegaParticipantesAlbum(Album* album, int pos) {
    return album->participantes[pos];
}

char* pegaDataLancamentoAlbum(Album* album) {
    return album->dataLancamento;
}

int pegaQtdMidiasAlbum(Album* album) {
    int qtd = 0;

    for (int i = 0; i < 20; i++) {
        if (album->midia[i]) qtd++;
    }

    return qtd;
}

int pegaIdAlbum(Album* album) {
    return album->idAlbum;
}

int* pegaMidiaAlbum(Album* album) {
    return album->midia;
}

void imprimeAlbum(Album* album) {
    printf("\nID: %d", pegaIdAlbum(album));
    printf("\nNome: %s", pegaNomeAlbum(album));
    for (int i = 0; i < 3 && pegaParticipantesAlbum(album, i)[0] != '\0'; i++)
        printf("\nParticipante %d: %s", i+1, pegaParticipantesAlbum(album, i));
    printf("\nQuantidade midias: %d", pegaQtdMidiasAlbum(album));
    printf("\nLancado em: %s", pegaDataLancamentoAlbum(album));
}

void destroiAlbum(Album* album) {
    if (album != NULL) {
        free(album);
    }
}

int listarTodosAlbuns() {
    Album* album = (Album*) malloc(sizeof (Album) * 50);
    int i = 0;

    if (album == NULL) {
        printf("\nErro ao alocar espaco para album!");
        getchar();
        scanf("%*c");
        return 0;
    }

    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL) {
        printf("\nAinda não existem albuns cadastrados!");
        return 0;
    }

    fread(album, sizeof (Album), 1, arqAlbum);
    do {
        imprimeAlbum(album);
        printf("\n----------");
        fread(album, sizeof (Album), 1, arqAlbum);
    } while (!feof(arqAlbum));

    fclose(arqAlbum);

    return 1;
}

Album* buscarAlbum(int idAlbum) {
    Album *album = alocarAlbum(1);

    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de album!");
        getchar();
        scanf("%*c");
        return NULL;
    }

    while (fread(album, sizeof (Album), 1, arqAlbum) == 1 && pegaIdAlbum(album) != idAlbum);

    fclose(arqAlbum);

    return album;
}

void adicionarMidiasAlbum(Album* album, Midia* midia) {
    int pos = pegaQtdMidiasAlbum(album);

    (album)->midia[pos] = pegaIdMidia(midia);
    modificaQtdMidias((album), pos + 1);
    atualizarArquivoAlbuns(album);
}

int quantidadeAlbunsCadastrados() {
    Album* album = (Album*) malloc(sizeof (Album) * 50);
    int i = 0;

    if (album == NULL) {
        printf("\nErro ao alocar espaco para album!");
        getchar();
        scanf("%*c");
    }

    FILE *arqAlbum;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL) {
        printf("\nAinda não existem albuns cadastrados!");
        return 0;
    }

    while (fread(album, sizeof (Album), 1, arqAlbum) == 1) {
        i++;
    }

    fclose(arqAlbum);

    return i;
}

void salvarAlbumArquivo(Album* album) {
    FILE* arqAlbuns;

    if ((arqAlbuns = fopen("albuns.dat", "ab")) == NULL) {
        printf("\nErro ao abrir arquivo de albuns!");
        getchar();
        scanf("%*c");
    }

    if ((fwrite(album, sizeof (Album), 1, arqAlbuns)) == 1) {
        printf("\nAlbum adicionado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    fclose(arqAlbuns);
}

void atualizarArquivoAlbuns(Album* album) {
    int i = 0;
    Album* albumAux = alocarAlbum(1);

    FILE* arqAlbuns;

    if ((arqAlbuns = fopen("albuns.dat", "r+b")) == NULL) {
        printf("\nErro ao abrir arquivo de albuns!");
        getchar();
        scanf("%*c");
    }

    while (fread(albumAux, sizeof (Album), 1, arqAlbuns) == 1 && pegaIdAlbum(albumAux) != pegaIdAlbum(album)) {
        i++;
    }

    fseek(arqAlbuns, i * sizeof (Album), SEEK_SET);

    if ((fwrite(album, sizeof (Album), 1, arqAlbuns)) == 1) {
        printf("\nAlbum atualizado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    destroiAlbum(albumAux);
    fclose(arqAlbuns);
}

void imprimirMidiasAlbum(Album* album) {
    int qtdMidias = pegaQtdMidiasAlbum(album);
    Midia* midia = alocarMidia(1);

    for (int i = 0; i < qtdMidias; i++) {
        midia = buscarMidia(pegaMidiaAlbum(album)[i]);
        imprimeMidia(midia);
        printf("\n-----------");
    }
}

void removeMidiaAlbum(Album* album, Midia* midia) {
    int qtdMidiasAlbum = pegaQtdMidiasAlbum(album);
    int pos = 0, excluiu = 0;
    int* vetMidias = pegaMidiaAlbum(album);

    for (pos = 0; pos < qtdMidiasAlbum; pos++) {
        if (excluiu) {
            vetMidias[pos - 1] = vetMidias[pos];
            vetMidias[pos] = 0;
        }
        if (vetMidias[pos] == pegaIdMidia(midia)) {
            vetMidias[pos] = 0;
            excluiu = 1;
        }
    }

    modificaQtdMidias(album, pegaQtdMidiasAlbum(album));
    atualizarArquivoAlbuns(album);
}

void excluirAlbumArquivo(Album* album) {
    FILE* arqAlbum;
    Album* listaAlbuns = alocarAlbum(50);
    Album* albumAux = alocarAlbum(1);
    int qtd = quantidadeAlbunsCadastrados(), removeu = 0, qtdMidiasAlbum = pegaQtdMidiasAlbum(album);

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de album!");
        getchar();
        scanf("%*c");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fread(albumAux, sizeof (Album), 1, arqAlbum);
        if (pegaIdAlbum(listaAlbuns + i) == pegaIdAlbum(album)) {
            for (int j = 0; j < qtdMidiasAlbum; j++) {
                excluirMidiaArquivo(buscarMidia(pegaMidiaAlbum(albumAux)[j]), 1);
            }
            removeu = 1;
        } else if (removeu) {
            listaAlbuns[i - 1] = *albumAux;
        } else {
            listaAlbuns[i] = *albumAux;
        }
    }

    destroiAlbum(albumAux);
    fclose(arqAlbum);

    if ((arqAlbum = fopen("albuns.dat", "wb")) == NULL) {
        printf("\nErro ao abrir arquivo de album!");
        getchar();
        scanf("%*c");
        return;
    }

    if (qtd > 1) fwrite(listaAlbuns, sizeof (Album), qtd - 1, arqAlbum);
    fclose(arqAlbum);
    destroiAlbum(listaAlbuns);
}

int pegaUltimoIdAlbumCadastrado() {
    FILE* arqAlbum;
    Album* album = alocarAlbum(1);
    int ultimoId;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL) {
        return 0;
    }

    while (fread(album, sizeof (Album), 1, arqAlbum) == 1);

    ultimoId = album->idAlbum;

    destroiAlbum(album);
    fclose(arqAlbum);

    return ultimoId;
}

void listarAlbunsFiltro(int tipoFiltro, char* string, int numero) {
    FILE* arqAlbum;
    Album* album = alocarAlbum(1);
    char* stringAux = NULL;

    if ((arqAlbum = fopen("albuns.dat", "rb")) == NULL) {
        printf("\nAinda nao possuem albuns cadastradas!");
        getchar();
        scanf("%*c");
        return;
    }

    printf("\nListando albuns encontradas...");

    switch (tipoFiltro) {
        case 1:
            while (fread(album, sizeof (Album), 1, arqAlbum) == 1) {
                stringAux = strstr(pegaNomeAlbum(album), string);
                if (stringAux) {
                    imprimeAlbum(album);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;

        case 2:
            //participantes
            break;

        case 3:
            while (fread(album, sizeof (Album), 1, arqAlbum) == 1) {
                stringAux = strstr(pegaDataLancamentoAlbum(album), string);
                if (stringAux) {
                    imprimeAlbum(album);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;
    }

    fclose(arqAlbum);
    destroiAlbum(album);
}
