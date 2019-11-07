#include <stdio.h>
#include "playlist.h"
#include "album.h"
#include "usuario.h"
#include "midia.h"
#include "impressoes.h"
#include <stdlib.h>
#include <string.h>

void fazerLogin();
void cadastrarUsuario(int verificador);
void menuAdmin();
void menuUsuario();
void gerenciarMidia();
void gerenciarPlaylst();
void gerenciarAlbuns();
void gerenciarUsuarios();
void lerMidia(Album* album);
void editarMidia(Midia* midia);
void menuListarTodasMidias();
void menuListarTodosAlbuns();
void editarAlbum(Album* album);
void excluirMidia();
Album* lerAlbum();

int main(int argc, char** argv) {
    int opcao;

    do {
        //system("clear");
        imprimeMenuPrincipal();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                fazerLogin();
                break;

            case 2:
                cadastrarUsuario(0);
                break;
        }

    } while (opcao != 3);


    return 0;
}

void fazerLogin() {
    int op;
    printf("Digite 0 para menu normal ou 1 para menu admin: ");
    scanf("%d", &op);

    if (op) {
        menuAdmin();
        return;
    }
    menuUsuario();

}

void cadastrarUsuario(int verificador) {
    char nome[50], senha[15];
    int tipo;
    Usuario* usuario;
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua senha: ");
    scanf("%s", senha);
    if (verificador) {
        printf("Digite o tipo de usuario: ");
        scanf("%d", &tipo);
    } else {
        tipo = 0;
    }

    usuario = inicializaUsuario(nome, tipo, senha);

    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "ab")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return;
    }

    if (fwrite(usuario, 73, 1, arqUsuarios) == 1) {
        printf("\nUsuario cadastrado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    fclose(arqUsuarios);
}

void menuAdmin() {
    int opcao;

    do {
        //system("clear")
        imprimeMenuOpcoesAdmin();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                gerenciarMidia();
                break;

            case 2:
                gerenciarPlaylst();
                break;

            case 3:
                gerenciarAlbuns();
                break;

            case 4:
                gerenciarUsuarios();
                break;

        }
    } while (opcao != 5);
}

void gerenciarMidia() {
    int opcao;

    do {
        //system("clear")
        imprimeMenuGerenciarMidia();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerMidia(NULL);
                break;

            case 2:
                menuListarTodasMidias();
                break;

            case 3:
                imprimeMenuBuscarMidias();
                break;
        }
    } while (opcao != 4);
}

void lerMidia(Album* album) {
    char nome[50], compositores[3][50], artistas[3][50], genero[15], gravadora[15], duracao[10];
    int tipo, qtdCompositores, qtdArtistas, i, j, idAlbum;
    Midia* midia;

    getchar();
    printf("\nDigite o nome da midia: ");
    scanf("%[^\n]s", nome);
    printf("\nDigite o tipo de midia (0 musica, 1 video): ");
    scanf("%d", &tipo);
    printf("\nDigite quantos compositores a midia possui: ");
    scanf("%d%*c", &qtdCompositores);
    for (i = 0; i < qtdCompositores; i++) {
        printf("\nDigite o compositor %d: ", i + 1);
        scanf("%[^\n]s%*c", compositores[i]);
    }
    for (i; i < qtdCompositores; i++) {
        compositores[i][0] = '\0';
    }
    printf("\nDigite quantos artistas a midia possui: ");
    scanf("%d%*c", &qtdArtistas);
    for (i = 0; i < qtdArtistas; i++) {
        printf("\nDigite o artista %d: ", i + 1);
        scanf("%[^\n]s%*c", artistas[i]);
    }
    for (i; i < qtdArtistas; i++) {
        artistas[i][0] = '\0';
    }
    printf("\nDigite o genero da midia: ");
    scanf("%s%*c", genero);
    printf("\nDigite a gravadora da midia: ");
    scanf("%[^\n]s", gravadora);
    printf("\nDigite a duracao da midia (MM:SS): ");
    scanf("%s", duracao);
    if (album == NULL) {
        printf("\nEscolha o album a qual a midia pertence: ");
        listarTodosAlbuns();
        printf("\nDigite o id do album desejado, ou 0 para adicionar um novo album: ");
        scanf("%d", &idAlbum);
        if (!idAlbum) {
            album = lerAlbum();
        } else {
            album = buscarAlbum(idAlbum);
        }
    }
    midia = inicializaMidia(nome, tipo, compositores, artistas, genero, gravadora, duracao, pegaIdAlbum(album));
    adicionarMidiasAlbum(album, midia);
    salvarMidiaArquivo(midia);

}

void menuListarTodasMidias() {
    printf("\nListando todas as midias...");
    if (listarTodasMidias()) {
        Midia* midia = alocarMidia(1);
        int id;
        printf("\nDigite o id da midia ou 0 para voltar: ");
        scanf("%d", &id);

        if (id) {
            midia = buscarMidia(id);
            editarMidia(buscarMidia(id));
            destroiMidia(midia);
        }
    } else {
        printf("\nArquivo de midias vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
        scanf("%*c");
    }
}

void editarMidia(Midia* midia) {
    char nome[50], compositores[3][50], artistas[3][50], genero[15], gravadora[15], duracao[10];
    int tipo, opcaoMenu;

    do {
        imprimeMenuOpcoesMidiaAdmin();
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 1:
                printf("\nDigite o novo nome para a midia: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaNomeMidia(midia, nome);
                atualizarArquivoMidias(midia);
                break;

            case 2:
                printf("\nDigite o novo tipo para a midia (0 musica, 1 video): ");
                scanf("%d", &tipo);
                modificaTipoMidia(midia, tipo);
                atualizarArquivoMidias(midia);
                break;

            case 3:
                /* code */
                break;

            case 4:
                /* code */
                break;

            case 5:
                /* code */
                break;

            case 6:
                /* code */
                break;

            case 7:
                /* code */
                break;

            case 8:
                /* code */
                break;

        }
    } while (opcaoMenu != 9);
}

void excluirMidia() {

}

void gerenciarPlaylst() {

}

void gerenciarAlbuns() {
    int opcao;

    do {
        //system("clear")
        imprimeMenuGerenciarAlbuns();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerAlbum();
                break;

            case 2:
                menuListarTodosAlbuns();
                break;

            case 3:
                //imprimeMenuBuscarAlbuns();
                break;

        }
    } while (opcao != 4);
}

void gerenciarUsuarios() {

}

Album* lerAlbum() {
    char nome[50], particiapantes[3][50], dataLancamento[11];
    int qtdParticipantes, i;
    Album* album;
    getchar();
    printf("\nDigite o nome do album: ");
    scanf("%[^\n]s", nome);
    printf("\nDigite a quantidade de participantes do album: ");
    scanf("%d%*c", &qtdParticipantes);
    for (i = 0; i < qtdParticipantes; i++) {
        printf("\nDigite o participante %d: ", i);
        scanf("%[^\n]s%*c", particiapantes[i]);
    }
    for (i; i < qtdParticipantes; i++) {
        particiapantes[i][0] = '\0';
    }
    printf("\nDigite a data de lancamento do album (DD:MM:AAAA): ");
    scanf("%s", dataLancamento);

    album = inicializaAlbum(nome, particiapantes, dataLancamento);

    salvarAlbumArquivo(album);

    return album;
}

void menuUsuario() {

}

void menuListarTodosAlbuns() {
    printf("\nListando todos os albuns...");
    if (listarTodosAlbuns()) {
        Album* album = alocarAlbum(album, 1);
        int id;
        printf("\nDigite o id do album ou 0 para voltar: ");
        scanf("%d", &id);

        if (id) {
            album = buscarAlbum(id);
            editarAlbum(buscarAlbum(id));
            //free(album); usar funcao destruir ponteiro
        }
    } else {
        printf("\nArquivo de midias vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
        scanf("%*c");
    }
}

void editarAlbum(Album* album) {
    char nome[50], participantes[3][50], dataLancamento[10];
    int opcaoMenu;

    do {
        imprimeMenuOpcoesAlbumAdmin();
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 1:
                printf("\nDigite o novo nome para o album: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaNomeAlbum(album, nome);
                atualizarArquivoAlbuns(album);
                break;

            case 2:
                //editar participantes
                break;

            case 3:
                printf("\nDigite a nova data de lancamento para o album: ");
                getchar();
                scanf("%[^\n]s", dataLancamento);
                modificaDataLancamentoAlbum(album, dataLancamento);
                atualizarArquivoAlbuns(album);
                break;

            case 4:
                lerMidia(album);
                break;

            case 5:
                imprimirMidiasAlbum(album);
                break;
        }

    } while (opcaoMenu != 6);
}