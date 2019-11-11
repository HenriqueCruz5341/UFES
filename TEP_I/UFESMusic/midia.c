#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midia.h"
#include "album.h"

struct midia {
    int idMidia;
    char nome[50];
    int tipo; // Musica = 0, Video = 1
    char compositores[3][50];
    char artistas[3][50];
    char genero[15];
    char gravadora[15];
    char duracao[10];
    int idAlbum;
};

Midia* inicializaMidia(char* nome, int tipo, char compositores[][50], char artistas[][50], char* genero, char* gravadora, char* duracao, int idAlbum) {
    Midia* midia = (Midia*) malloc(sizeof (Midia));

    if (midia == NULL) {
        printf("Erro ao adicionar nova midia!");
        getchar();
        scanf("%*c");
    }

    midia->idMidia = pegaUltimoIdMidiaCadastrado() + 1;
    strcpy(midia->nome, nome);
    midia->tipo = tipo;
    for (int i = 0; i < 3; i++) {
        strcpy(midia->compositores[i], compositores[i]);
        strcpy(midia->artistas[i], artistas[i]);
    }
    strcpy(midia->genero, genero);
    strcpy(midia->gravadora, gravadora);
    strcpy(midia->duracao, duracao);
    midia->idAlbum = idAlbum;

    return midia;
}

Midia* alocarMidia(int qtd) {
    return (Midia*) malloc(sizeof (Midia) * qtd);
}

void modificaNomeMidia(Midia* midia, char* nNome) {
    strcpy(midia->nome, nNome);
}

void modificaTipoMidia(Midia* midia, int nTipo) {

}

void modificaCompositoresMidia(Midia* midia, char* nCompositor) {

}

void modificaArtistasMidia(Midia* midia, char* nArtista) {

}

void modificaGeneroMidia(Midia* midia, char* nGenero) {

}

void modificaGravadoraMidia(Midia* midia, char* nGravadora) {

}

void modificaDuracaoMidia(Midia* midia, char* nDuracao) {

}

char* pegaNomeMidia(Midia* midia) {
    return midia->nome;
}

int pegaTipoMidia(Midia* midia) {
    return midia->tipo;
}

char** pegaCompositoresMidia(Midia* midia) {
    //return midia->compositores;
}

char** pegaArtistasMidia(Midia* midia) {
    //return midia->artistas;
}

char* pegaGeneroMidia(Midia* midia) {
    return midia->genero;
}

char* pegaGravadoraMidia(Midia* midia) {
    return midia->gravadora;
}

char* pegaDuracaoMidia(Midia* midia) {
    return midia->duracao;
}

int pegaIdMidia(Midia* midia) {
    return midia->idMidia;
}

int pegaAlbumMidia(Midia *midia) {
    return midia->idAlbum;
}

void imprimeMidia(Midia* midia) {
    printf("\nID: %d", pegaIdMidia(midia));
    printf("\nNome: %s", pegaNomeMidia(midia));
    printf("\nDuracao: %s", pegaDuracaoMidia(midia));
    printf("\nGenero: %s", pegaGeneroMidia(midia));
    printf("\nAlbum: %s", pegaNomeAlbum(buscarAlbum(pegaAlbumMidia(midia))));
}

void destroiMidia(Midia* midia) {
    if (midia != NULL) {
        free(midia);
    }
}

void atualizarArquivoMidias(Midia* midia) {
    FILE *arqMidia;
    int i = 0;
    Midia* midiaLida = alocarMidia(1);

    if ((arqMidia = fopen("midias.dat", "r+b")) == NULL) {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
        return;
    }

    while (fread(midiaLida, sizeof (Midia), 1, arqMidia) == 1 && pegaIdMidia(midiaLida) != pegaIdMidia(midia)) i++;

    fseek(arqMidia, sizeof (Midia) * i, SEEK_SET);

    if (fwrite(midia, sizeof (Midia), 1, arqMidia) == 1) {
        printf("\nArquivo de midias atualizado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    destroiMidia(midiaLida);
    fclose(arqMidia);
}

int listarTodasMidias() {
    Midia* midia = (Midia*) malloc(sizeof (Midia));

    if (midia == NULL) {
        printf("\nErro ao alocar espaco para midia!");
        getchar();
        scanf("%*c");
        return 0;
    }

    FILE *arqMidia;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
        return 0;
    }

    fread(midia, sizeof (Midia), 1, arqMidia);
    do {
        imprimeMidia(midia);
        printf("\n----------");
        fread(midia, sizeof (Midia), 1, arqMidia);
    } while (!feof(arqMidia));

    fclose(arqMidia);
    return 1;
}

Midia* buscarMidia(int idMidia) {
    Midia *midia = alocarMidia(1);

    if (midia == NULL) {
        printf("\nErro ao alocar espaco para midia!");
        getchar();
        scanf("%*c");
        return NULL;
    }

    FILE *arqMidia;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
        return NULL;
    }

    while (fread(midia, sizeof (Midia), 1, arqMidia) == 1 && pegaIdMidia(midia) != idMidia);

    fclose(arqMidia);

    return midia;
}

int quantidadeMidiasCadastradas() {
    Midia* midia = (Midia*) malloc(sizeof (Midia) * 50);
    int i = 0;

    if (midia == NULL) {
        printf("\nErro ao alocar espaco para midia!");
        getchar();
        scanf("%*c");
        return 0;
    }

    FILE *arqMidia;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL) return 0;

    while (fread(midia + i, sizeof (Midia), 1, arqMidia) == 1) i++;

    fclose(arqMidia);
    destroiMidia(midia);

    return i;

}

void excluirMidiaArquivo(Midia* midia, int excluindoAlbum) { // esse int eh para saber se a exclusao da midia esta sendo por ela mesmo, por excluir um album
    FILE *arqMidia;
    Midia* listaMidias = alocarMidia(50);
    Midia* midiaAux = alocarMidia(1);
    int qtd = quantidadeMidiasCadastradas(), removeu = 0;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fread(midiaAux, sizeof (Midia), 1, arqMidia);
        if (pegaIdMidia(midiaAux) == pegaIdMidia(midia)) {
            if (!excluindoAlbum) removeMidiaAlbum(buscarAlbum(pegaAlbumMidia(midiaAux)), midiaAux);
            removeu = 1;
        } else if (removeu) {
            listaMidias[i - 1] = *midiaAux;
        } else {
            listaMidias[i] = *midiaAux;
        }

    }
    destroiMidia(midiaAux);
    fclose(arqMidia);

    if ((arqMidia = fopen("midias.dat", "wb")) == NULL) {
        printf("\nErro ao abrir arquivo de midia!");
        getchar();
        scanf("%*c");
        return;
    }
    if (qtd > 1) fwrite(listaMidias, sizeof (Midia), qtd - 1, arqMidia);
    fclose(arqMidia);

    destroiMidia(listaMidias);
}

void salvarMidiaArquivo(Midia* midia) {
    FILE* arqMidias;

    if ((arqMidias = fopen("midias.dat", "ab")) == NULL) {
        printf("\nErro ao abrir arquivo de midias!");
        getchar();
        scanf("%*c");
    }

    if (fwrite(midia, sizeof (Midia), 1, arqMidias) == 1) {
        printf("\nNova midia adicionada com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    fclose(arqMidias);
}

int pegaUltimoIdMidiaCadastrado() {
    Midia* midia = alocarMidia(1);
    int ultimoId;

    FILE *arqMidia;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL) {
        return 0;
    }

    while (fread(midia, sizeof (Midia), 1, arqMidia) == 1);

    ultimoId = pegaIdMidia(midia);
    destroiMidia(midia);
    fclose(arqMidia);

    return ultimoId;
}

void listarMidiasFiltro(int tipoFiltro, char* string, int numero) {
    FILE* arqMidia;
    Midia* midia = alocarMidia(1);
    char* stringAux = NULL;

    if ((arqMidia = fopen("midias.dat", "rb")) == NULL) {
        printf("\nAinda nao possuem midias cadastradas!");
        getchar();
        scanf("%*c");
        return;
    }

    printf("\nListando midias encontradas...");

    switch (tipoFiltro) {
        case 1:
            while (fread(midia, sizeof (Midia), 1, arqMidia) == 1) {
                stringAux = strstr(pegaNomeMidia(midia), string);
                if (stringAux) {
                    imprimeMidia(midia);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;

        case 2:
            while (fread(midia, sizeof (Midia), 1, arqMidia) == 1) {
                if (pegaTipoMidia(midia) == numero) {
                    imprimeMidia(midia);
                    printf("\n-----------");
                }
            }
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 5:
            while (fread(midia, sizeof (Midia), 1, arqMidia) == 1) {
                stringAux = strstr(pegaGeneroMidia(midia), string);
                if (stringAux) {
                    imprimeMidia(midia);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;

        case 6:
            while (fread(midia, sizeof (Midia), 1, arqMidia) == 1) {
                stringAux = strstr(pegaGravadoraMidia(midia), string);
                if (stringAux) {
                    imprimeMidia(midia);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;

        case 7:
            while (fread(midia, sizeof (Midia), 1, arqMidia) == 1) {
                stringAux = strstr(pegaNomeAlbum(buscarAlbum(pegaAlbumMidia(midia))), string);
                if (stringAux) {
                    imprimeMidia(midia);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;

        default:
            break;
    }

    fclose(arqMidia);
    destroiMidia(midia);
}