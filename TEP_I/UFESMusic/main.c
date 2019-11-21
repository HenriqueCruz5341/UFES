#include <stdio.h>
#include "playlist.h"
#include "album.h"
#include "usuario.h"
#include "midia.h"
#include "impressoes.h"
#include "sistema.h"
#include <stdlib.h>
#include <string.h>

void fazerLogin();
void menuAdmin(Usuario** usuarioLogado);
void menuUsuario(Usuario** usuarioLogado);

void gerenciarMidia(Usuario** usuarioLogado);
void lerMidia(Album* album);
void opcoesMidiaAdmin(Midia* midia);
void opcoesMidiaPublico(Midia* midia, Usuario** usuarioLogado);
void selecionarMidia(Usuario** usuarioLogado);
void menuListarTodasMidias(Usuario** usuarioLogado);
void menuBuscarMidias(Usuario** usuarioLogado);
int excluirMidia(Midia* midia);

void gerenciarPlaylst(Usuario** usuarioLogado);
void menuGerenciarMinhasPlaylists(Usuario** usuarioLogado);
Playlist* lerPlaylist();
void selecionarPlaylist(Usuario** usuarioLogado);
void menuListarTodasPlaylists(Usuario** usuarioLogado);
void menuBuscarPlaylists(Usuario** usuarioLogado);
void opcoesPlaylistDono(Playlist* playlist, Usuario** usuarioLogado);
void opcoesPlaylistPublico(Playlist* playlist, Usuario** usuarioLogado);
int excluirPlaylist(Playlist* playlist);

void gerenciarAlbuns(Usuario** usuarioLogado);
Album* lerAlbum();
void selecionarAlbum(Usuario** usuarioLogado);
void menuListarTodosAlbuns(Usuario** usuarioLogado);
void menuBuscarAlbuns(Usuario** usuarioLogado);
void opcoesAlbumAdmin(Album* album);
void opcoesAlbumPublico(Album* album, Usuario** usuarioLogado);
int excluirAlbum(Album* album);

void gerenciarUsuarios();
void lerUsuario(int verificador);
void selecionarUsuario();
void menuListarTodosUsuarios();
void menuBuscarUsuarios();
void opcoesUsuariosAdmin(Usuario* usuario);
void opcoesUsuarioPublico(Usuario** usuarioLogado);
int excluirUsuario(Usuario* usuario);

int main(int argc, char** argv) {
    int opcao;

    do {
        imprimeMenuPrincipal();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                fazerLogin();
                break;

            case 2:
                lerUsuario(0);
                break;
        }
    } while (opcao != 3);


    return 0;
}

void fazerLogin() {
    /*int op;
    printf("Digite 0 para menu normal ou 1 para menu admin: ");
    scanf("%d", &op);

    if (op) {
        menuAdmin();
        return;
    }
    //menuUsuario();
     */
    char nome[50], senha[15];
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua senha: ");
    scanf("%s", senha);
    Usuario* usuarioLogado = alocarUsuario(1);
    usuarioLogado = autenticarUsuario(nome, senha);

    if (usuarioLogado == NULL) {
        printf("\nNome ou senha estao incorretos, tente novamente.");
        getchar();
        scanf("%*c");
        return;
    }

    if (pegaTipoUsuario(usuarioLogado)) {
        menuAdmin(&usuarioLogado);
    } else {
        menuUsuario(&usuarioLogado);
    }
}

void menuAdmin(Usuario** usuarioLogado) {
    int opcao;

    do {
        imprimeMenuOpcoesAdmin();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                gerenciarMidia(usuarioLogado);
                break;

            case 2:
                gerenciarPlaylst(usuarioLogado);
                break;

            case 3:
                gerenciarAlbuns(usuarioLogado);
                break;

            case 4:
                gerenciarUsuarios(usuarioLogado);
                break;

        }
    } while (opcao != 5);
}

void gerenciarMidia(Usuario** usuarioLogado) {
    int opcao;

    do {
        imprimeMenuGerenciarMidia();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerMidia(NULL);
                break;

            case 2:
                menuListarTodasMidias(usuarioLogado);
                break;

            case 3:
                menuBuscarMidias(usuarioLogado);
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
    scanf("%d", &qtdCompositores);
    for (i = 0; i < qtdCompositores; i++) {
        printf("\nDigite o compositor %d: ", i + 1);
        getchar();
        scanf("%[^\n]s", compositores[i]);
    }
    for (i; i < 3; i++) {
        compositores[i][0] = '\0';
    }
    printf("\nDigite quantos artistas a midia possui: ");
    scanf("%d", &qtdArtistas);
    for (i = 0; i < qtdArtistas; i++) {
        printf("\nDigite o artista %d: ", i + 1);
        getchar();
        scanf("%[^\n]s", artistas[i]);
    }
    for (i; i < 3; i++) {
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
    salvarMidiaArquivo(midia);
    adicionarMidiasAlbum(album, midia);
}

void menuListarTodasMidias(Usuario** usuarioLogado) {
    printf("\nListando todas as midias...");
    if (listarTodasMidias()) {
        selecionarMidia(usuarioLogado);
    } else {
        printf("\nArquivo de midias vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
    }
}

void selecionarMidia(Usuario** usuarioLogado) {
    int id;
    printf("\nDigite o id da midia ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        if (pegaTipoUsuario(*usuarioLogado)) opcoesMidiaAdmin(buscarMidia(id));
        else opcoesMidiaPublico(buscarMidia(id), usuarioLogado);
    }
}

void menuBuscarMidias(Usuario** usuarioLogado) {
    int opcaoMenu;
    char string[50];
    int tipo;

    do {
        imprimeMenuBuscarMidias();
        scanf("%d", &opcaoMenu);
        getchar();
        switch (opcaoMenu) {
            case 1:
                printf("Digite o nome ou parte do nome da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(1, string, tipo);
                selecionarMidia(usuarioLogado);
                break;

            case 2:
                printf("Digite o tipo da midia que deseja procurar: ");
                scanf("%d", &tipo);
                getchar();
                listarMidiasFiltro(2, string, tipo);
                selecionarMidia(usuarioLogado);
                break;

            case 3:
                printf("Digite o nome ou parte do nome do compositor da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(3, string, tipo);
                selecionarMidia(usuarioLogado);
                break;

            case 4:
                printf("Digite o nome ou parte do nome do artista da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(4, string, tipo);
                selecionarMidia(usuarioLogado);
                break;

            case 5:
                printf("Digite o genero ou parte do genero da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(5, string, tipo);
                selecionarMidia(usuarioLogado);
                break;

            case 6:
                printf("Digite a gravadora ou parte da gravadora da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(6, string, tipo);
                selecionarMidia(usuarioLogado);
                break;

            case 7:
                printf("Digite o album ou parte do album da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(7, string, tipo);
                selecionarMidia(usuarioLogado);
                break;

            case 8:
                menuListarTodasMidias(usuarioLogado);
                break;
        }
    } while (opcaoMenu != 9);

}

void opcoesMidiaAdmin(Midia* midia) {
    char nome[50], compositores[3][50], artistas[3][50], genero[15], gravadora[15], duracao[10];
    int tipo, opcaoMenu, excluiu, indice;

    do {
        imprimeMenuOpcoesMidiaAdmin();
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 1:
                printf("O nome atual da midia eh: %s", pegaNomeMidia(midia));
                printf("\nDigite o novo nome para a midia: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaNomeMidia(midia, nome);
                atualizarArquivoMidias(midia);
                break;

            case 2:
                printf("O tipo atual da midia eh: %d", pegaTipoMidia(midia));
                printf("\nDigite o novo tipo para a midia (0 musica, 1 video): ");
                scanf("%d", &tipo);
                modificaTipoMidia(midia, tipo);
                atualizarArquivoMidias(midia);
                break;

            case 3:
                printf("Qual o indice do compositor deseja alterar? ");
                scanf("%d", &indice);
                printf("O nome desse compositor atual da midia eh: %s", pegaCompositoresMidia(midia, indice - 1));
                printf("\nDigite o novo compositor para a midia: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaCompositoresMidia(midia, nome, indice - 1);
                atualizarArquivoMidias(midia);
                break;

            case 4:
                printf("Qual o indice do artista deseja alterar? ");
                scanf("%d", &indice);
                printf("O nome desse artista atual da midia eh: %s", pegaArtistasMidia(midia, indice - 1));
                printf("\nDigite o novo artista para a midia: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaArtistasMidia(midia, nome, indice - 1);
                atualizarArquivoMidias(midia);
                break;

            case 5:
                printf("O genero atual da midia eh: %s", pegaGeneroMidia(midia));
                printf("\nDigite o novo genero para a midia: ");
                scanf("%[^\n]s", genero);
                modificaGeneroMidia(midia, genero);
                atualizarArquivoMidias(midia);
                break;

            case 6:
                printf("A gravadora atual da midia eh: %s", pegaGravadoraMidia(midia));
                printf("\nDigite a nova gravadora para a midia: ");
                scanf("%[^\n]s", gravadora);
                modificaGravadoraMidia(midia, gravadora);
                atualizarArquivoMidias(midia);
                break;

            case 7:
                printf("A duracao atual da midia eh: %s", pegaDuracaoMidia(midia));
                printf("\nDigite a nova duracao para a midia: ");
                scanf("%[^\n]s", duracao);
                modificaDuracaoMidia(midia, duracao);
                atualizarArquivoMidias(midia);
                break;

            case 8:
                excluiu = excluirMidia(midia);
                if (excluiu) return;

                break;
        }
    } while (opcaoMenu != 9);
}

int excluirMidia(Midia* midia) { //retorna 1 se excluiu a midia, e 0 caso n tenha excluido
    int op;
    printf("Tem certeza que deseja excluir esta midia? (0/1)");
    scanf("%d", &op);
    if (op) {
        excluirMidiaArquivo(midia, 0);
        return 1;
    }

    return 0;
}

void gerenciarPlaylst(Usuario** usuarioLogado) {
    int opcao;

    do {
        imprimeMenuGerenciarPlaylists();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerPlaylist(NULL);
                break;

            case 2:
                menuListarTodasPlaylists(usuarioLogado);
                break;

            case 3:
                menuBuscarPlaylists(usuarioLogado);
                break;

        }
    } while (opcao != 4);
}

Playlist* lerPlaylist(Usuario** usuario) {
    char nome[50];
    int privacidade, contribuintes[2], teraContribuinte;
    Playlist* playlist = alocarPlaylist(1);

    printf("Digite o nome da playlist: ");
    getchar();
    scanf("%[^\n]s", nome);
    printf("0 - Individual | 1 - Compartilhada");
    printf("\nDigite a privacidade da playlist: ");
    scanf("%d", &privacidade);
    if (usuario == NULL) {
        listarTodosUsuarios();
        printf("\nDigite o ID do usuario que sera o dono: ");
        scanf("%d", &contribuintes[0]);
    } else contribuintes[0] = pegaIdUsuario(*usuario);
    if (privacidade) {
        listarTodosUsuarios();
        printf("\nDigite o ID do usuario que sera um contribuinte da playlist: ");
        scanf("%d", &contribuintes[1]);
    } else contribuintes[1] = 0;

    playlist = inicializaPlaylist(nome, privacidade, contribuintes);
    salvarPlaylistArquivo(playlist);
    adicionarPlaylistUsuario(buscarUsuario(contribuintes[0]), playlist);
    *usuario = buscarUsuario(contribuintes[0]);
    if (contribuintes[1] != 0) adicionarPlaylistUsuario(buscarUsuario(contribuintes[1]), playlist);

    return playlist;

}

void selecionarPlaylist(Usuario** usuarioLogado) {
    Playlist* playlist = alocarPlaylist(1);
    int id;
    printf("\nDigite o id da playlist ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        playlist = buscarPlaylist(id);
        if (pegaTipoUsuario(*usuarioLogado)) opcoesPlaylistDono(buscarPlaylist(id), usuarioLogado);
        else opcoesPlaylistPublico(buscarPlaylist(id), usuarioLogado);
    }
}

void menuListarTodasPlaylists(Usuario** usuarioLogado) {
    printf("\nListando todas as playlists...");
    if (listarTodasPlaylists()) {
        selecionarPlaylist(usuarioLogado);
    } else {
        printf("\nArquivo de playlists vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
    }
}

void menuBuscarPlaylists(Usuario** usuarioLogado) {
    int opcaoMenu;
    char string[50];
    int tipo;

    do {
        imprimeMenuBuscarPlaylists();
        scanf("%d", &opcaoMenu);
        getchar();
        switch (opcaoMenu) {
            case 1:
                printf("Digite o nome ou parte do nome da playlist que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarPlaylistsFiltro(1, string);
                selecionarPlaylist(usuarioLogado);
                break;

            case 2:
                printf("Digite o nome ou parte do nome do dono que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarPlaylistsFiltro(2, string);
                selecionarPlaylist(usuarioLogado);
                break;

            case 3:
                menuListarTodasPlaylists(usuarioLogado);
                break;
        }
    } while (opcaoMenu != 4);
}

void opcoesPlaylistDono(Playlist* playlist, Usuario** usuarioLogado) {
    char nome[50];
    int opcaoMenu, excluiu, numero, contribuinte, id, pos;

    do {
        imprimeMenuOpcoesPlaylistDono();
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 1:
                if (pegaTipoUsuario(*usuarioLogado) || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[0]) {
                    printf("O nome atual da playlist eh: %s", pegaNomePlaylist(playlist));
                    printf("\nDigite o novo nome para a playlist: ");
                    getchar();
                    scanf("%[^\n]s", nome);
                    modificaNomePlaylist(playlist, nome);
                    atualizarArquivoPlaylists(playlist);
                }
                break;

            case 2:
                if (pegaTipoUsuario(*usuarioLogado) || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[0]) {
                    printf("0 - Individual | 1 - Compartilhada");
                    printf("\nA privacidade atual dessa playlist eh: %d", pegaPrivacidadePlaylist(playlist));
                    printf("\nDigite o numero para a nova privacidade da playlist: ");
                    scanf("%d", &numero);
                    modificaPrivacidadePlaylist(playlist, numero);
                    atualizarArquivoPlaylists(playlist);
                }
                break;

            case 3:
                if (pegaTipoUsuario(*usuarioLogado) || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[0]) {
                    if (pegaPrivacidadePlaylist(playlist)) {
                        contribuinte = pegaContribuintesPlaylist(playlist)[1];
                        listarTodosUsuarios();
                        if (contribuinte) printf("O colaborador atual da playlist eh: %s", pegaNomeUsuario(buscarUsuario(contribuinte)));
                        else printf("\nA playlist nao possui contribuidor.");
                        printf("\nDigite o ID do usuario que sera o novo contribuinte da playlist: ");
                        scanf("%d", &numero);
                        modificaContribuintesPlaylist(playlist, numero);
                        atualizarArquivoPlaylists(playlist);
                        Usuario* usuario = alocarUsuario(1);
                        usuario = buscarUsuario(numero);
                        adicionarPlaylistUsuario(usuario, playlist);
                        atualizarArquivoUsuarios(usuario);
                    } else {
                        printf("Altere a privacidade da playlist para compartilhada primeiro!");
                        printf("\nPressione ENTER para voltar");
                        getchar();
                        scanf("%*c");
                    }

                }
                break;

            case 4:
                if (pegaTipoUsuario(*usuarioLogado) || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[0] || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[1]) {
                    printf("Listando todas as midias.");
                    listarTodasMidias();
                    printf("\nDigite o id da midia para adicionar a playlist ou 0 para voltar: ");
                    scanf("%d", &id);
                    if (id) adicionarMidiaPlaylist(playlist, buscarMidia(id));
                    atualizarArquivoPlaylists(playlist);
                }
                break;

            case 5:
                printf("Listando todas as midias.");
                listarMidiasPlaylist(playlist);
                printf("\nDigite o id da midia para remover da playlist ou 0 para voltar: ");
                scanf("%d", &id);
                if (id) removerMidiaPlaylist(playlist, buscarMidia(id));
                atualizarArquivoPlaylists(playlist);
                break;

            case 6:
                printf("Listando todas as midias da playlist.");
                listarMidiasPlaylist(playlist);
                printf("\nDigite 0 para voltar: ");
                scanf("%d", &numero);
                break;

            case 7:
                if (pegaTipoUsuario(*usuarioLogado) || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[0] || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[1]) {
                    printf("Listando todas as midias da playlist.");
                    listarMidiasPlaylist(playlist);
                    printf("\nDigite o id da midia que deseja alterar a posicao: ");
                    scanf("%d", &id);
                    printf("Digite a nova posicao que deseja colocar a midia: ");
                    scanf("%d", &pos);
                    trocarPosicaoMidiaPlaylist(playlist, buscarMidia(id), pos);
                    atualizarArquivoPlaylists(playlist);
                }
                break;

            case 8:
                if (pegaTipoUsuario(*usuarioLogado) || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[0]) {
                    excluiu = excluirPlaylist(playlist);
                    if (excluiu) return;
                }
                break;
        }

    } while (opcaoMenu != 9);
}

int excluirPlaylist(Playlist* playlist) {
    int op;
    printf("Tem certeza que deseja excluir esta playlist? (0/1)");
    scanf("%d", &op);

    if (op) {
        excluirPlaylistArquivo(playlist);
        return 1;
    }
    return 0;
}

void gerenciarAlbuns(Usuario** usuarioLogado) {
    int opcao;

    do {
        imprimeMenuGerenciarAlbuns();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerAlbum();
                break;

            case 2:
                menuListarTodosAlbuns(usuarioLogado);
                break;

            case 3:
                menuBuscarAlbuns(usuarioLogado);
                break;

        }
    } while (opcao != 4);
}

Album* lerAlbum() {
    char nome[50], particiapantes[3][50], dataLancamento[11];
    int qtdParticipantes, i;
    Album* album;
    getchar();
    printf("\nDigite o nome do album: ");
    scanf("%[^\n]s", nome);
    printf("\nDigite a quantidade de participantes do album: ");
    scanf("%d", &qtdParticipantes);
    for (i = 0; i < qtdParticipantes; i++) {
        printf("\nDigite o participante %d: ", i);
        getchar();
        scanf("%[^\n]s", particiapantes[i]);
    }
    for (i; i < 3; i++) {
        particiapantes[i][0] = '\0';
    }
    printf("\nDigite a data de lancamento do album (DD/MM/AAAA): ");
    scanf("%s", dataLancamento);

    album = inicializaAlbum(nome, particiapantes, dataLancamento);

    salvarAlbumArquivo(album);

    return album;
}

void menuListarTodosAlbuns(Usuario** usuarioLogado) {
    printf("\nListando todos os albuns...");
    if (listarTodosAlbuns()) {
        selecionarAlbum(usuarioLogado);
    } else {
        printf("\nArquivo de albuns vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
        scanf("%*c");
    }
}

void selecionarAlbum(Usuario** usuarioLogado) {
    Album* album = alocarAlbum(1);
    int id;
    printf("\nDigite o id do album ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        album = buscarAlbum(id);
        if (pegaTipoUsuario(*usuarioLogado)) opcoesAlbumAdmin(buscarAlbum(id));
        else opcoesAlbumPublico(buscarAlbum(id), usuarioLogado);
    }
}

void menuBuscarAlbuns(Usuario** usuarioLogado) {
    int opcaoMenu;
    char string[50];
    int tipo;

    do {
        imprimeMenuBuscarAlbuns();
        scanf("%d", &opcaoMenu);
        getchar();
        switch (opcaoMenu) {
            case 1:
                printf("Digite o nome ou parte do nome do album que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(1, string, tipo);
                selecionarAlbum(usuarioLogado);
                break;

            case 2:
                printf("Digite o nome ou parte do nome do participante que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(2, string, tipo);
                selecionarAlbum(usuarioLogado);
                break;

            case 3:
                printf("Digite a data de lancamento ou parte do album que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(3, string, tipo);
                selecionarAlbum(usuarioLogado);
                break;

            case 4:
                menuListarTodosAlbuns(usuarioLogado);
                break;
        }
    } while (opcaoMenu != 5);
}

void opcoesAlbumAdmin(Album* album) {
    char nome[50], dataLancamento[10];
    int opcaoMenu, excluiu, opcaoPart;

    do {
        imprimeMenuOpcoesAlbumAdmin();
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 1:
                printf("O nome atual do album eh: %s", pegaNomeAlbum(album));
                printf("\nDigite o novo nome para o album: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaNomeAlbum(album, nome);
                atualizarArquivoAlbuns(album);
                break;

            case 2:
                printf("Qual o indice do participante deseja alterar? ");
                scanf("%d", &opcaoPart);
                printf("O nome desse participante atual do album eh: %s", pegaParticipantesAlbum(album, opcaoPart - 1));
                printf("\nDigite o novo participante para o album: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaParticipantesAlbum(album, nome, opcaoPart - 1);
                atualizarArquivoAlbuns(album);
                break;

            case 3:
                printf("A data de lancamento atual do album eh: %s", pegaDataLancamentoAlbum(album));
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
                printf("Listando todas as midias do album...");
                imprimirMidiasAlbum(album);
                printf("\nPressione ENTER para voltar.");
                getchar();
                scanf("%*c");
                break;

            case 6:
                excluiu = excluirAlbum(album);
                if (excluiu) return;
                break;
        }

    } while (opcaoMenu != 7);
}

int excluirAlbum(Album* album) {
    int op;
    printf("\nExcluir o album tambem apagará todas suas midias!");
    printf("\nTem certeza que deseja excluir este album? (0/1)");
    scanf("%d", &op);

    if (op) {
        excluirAlbumArquivo(album);
        return 1;
    }
    return 0;
}

void gerenciarUsuarios() {
    int opcao;

    do {
        imprimeMenuGerenciarUsuarios();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerUsuario(1);
                break;

            case 2:
                menuListarTodosUsuarios();
                break;

            case 3:
                menuBuscarUsuarios();
                break;

        }
    } while (opcao != 4);
}

void lerUsuario(int verificador) {
    char nome[50], senha[15];
    int tipo, playlists[20];
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

    usuario = inicializaUsuario(nome, tipo, senha, playlists);

    salvarUsuarioArquivo(usuario);
}

void selecionarUsuario() {
    Usuario* usuario = alocarUsuario(1);
    int id;
    printf("\nDigite o id do usuaro ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        usuario = buscarUsuario(id);
        opcoesUsuariosAdmin(usuario);
    }
}

void menuListarTodosUsuarios() {
    printf("\nListando todos os usuarios...");
    if (listarTodosUsuarios()) {
        selecionarUsuario();
    } else {
        printf("\nArquivo de usuarios vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
        scanf("%*c");
    }
}

void menuBuscarUsuarios() {
    int opcaoMenu;
    char string[50];
    int tipo;

    do {
        imprimeMenuBuscarUsuarios();
        scanf("%d", &opcaoMenu);
        getchar();
        switch (opcaoMenu) {
            case 1:
                printf("Digite o nome ou parte do nome do usuario que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarUsuariosFiltro(1, string, tipo);
                selecionarUsuario();
                break;

            case 2:
                printf("Digite o tipo do usuario que deseja procurar: ");
                scanf("%d", &tipo);
                getchar();
                listarUsuariosFiltro(2, string, tipo);
                selecionarUsuario();
                break;

            case 3:
                menuListarTodosUsuarios();
                break;
        }
    } while (opcaoMenu != 4);
}

void opcoesUsuariosAdmin(Usuario* usuario) {
    char nome[50], senha[15];
    int opcaoMenu, excluiu, tipo;

    do {
        imprimeMenuOpcoesUsuarioAdmin();
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 1:
                printf("O nome atual do usuario eh: %s", pegaNomeUsuario(usuario));
                printf("\nDigite o novo nome para o usuario: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaNomeUsuario(usuario, nome);
                atualizarArquivoUsuarios(usuario);
                break;

            case 2:
                printf("A senha atual do usuario eh: %s", pegaSenhaUsuario(usuario));
                printf("\nDigite a nova senha para o usuario: ");
                getchar();
                scanf("%[^\n]s", senha);
                modificaSenhaUsuario(usuario, senha);
                atualizarArquivoUsuarios(usuario);
                break;

            case 3:
                printf("O tipo atual do usuario eh: %d", pegaTipoUsuario(usuario));
                printf("\nDigite o novo tipo para o usuario: ");
                scanf("%d", &tipo);
                modificaTipoUsuario(usuario, tipo);
                atualizarArquivoUsuarios(usuario);
                break;

            case 4:
                printf("Listando todas as playlists do usuario...");
                listarPlaylistsUsuario(usuario);
                printf("\nPressione ENTER para voltar.");
                getchar();
                scanf("%*c");
                break;

            case 5:
                excluiu = excluirUsuario(usuario);
                if (excluiu) return;
                break;
        }

    } while (opcaoMenu != 6);
}

int excluirUsuario(Usuario* usuario) {
    int op;
    printf("\nExcluir o usuario tambem apagará todas suas playlists!");
    printf("\nTem certeza que deseja excluir este usuario? (0/1)");
    scanf("%d", &op);

    if (op) {
        excluirUsuarioArquivo(usuario);
        return 1;
    }
    return 0;
}

void menuUsuario(Usuario** usuarioLogado) {
    int opcao;

    do {
        imprimeMenuOpcoesNormal();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                menuBuscarMidias(usuarioLogado);
                break;

            case 2:
                menuBuscarPlaylists(usuarioLogado);
                break;

            case 3:
                menuBuscarAlbuns(usuarioLogado);
                break;

            case 4:
                menuGerenciarMinhasPlaylists(usuarioLogado);
                break;

            case 5:
                opcoesUsuarioPublico(usuarioLogado);
                break;
        }
    } while (opcao != 6);
}

void opcoesMidiaPublico(Midia* midia, Usuario** usuarioLogado) {
    int opcao, id;

    do {
        imprimeMenuOpcoesMidiaPublico();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\nTocando agora: %s", pegaNomeMidia(midia));
                printf("\nPressione ENTER para voltar...");
                getchar();
                scanf("%*c");
                break;

            case 2:
                printf("Listando suas playlists...");
                listarPlaylistsUsuario(*usuarioLogado);
                printf("\nDigite o ID da playlist a qual voce deseja adicionar a midia, ou 0 para voltar: ");
                scanf("%d", &id);
                if (id) {
                    Playlist* playlist = buscarPlaylist(id);
                    adicionarMidiaPlaylist(playlist, midia);
                    atualizarArquivoPlaylists(playlist);
                }
                break;
        }
    } while (opcao != 3);
}

void opcoesPlaylistPublico(Playlist* playlist, Usuario** usuarioLogado) {
    int opcao, id;

    do {
        imprimeMenuOpcoesPlaylistPublico();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\nReproduzindo midias da playlist: %s", pegaNomePlaylist(playlist));
                printf("\nPressione ENTER para voltar...");
                getchar();
                scanf("%*c");
                break;

            case 2:
                adicionarPlaylistUsuario(*usuarioLogado, playlist);
                atualizarArquivoUsuarios(*usuarioLogado);
                break;

            case 3:
                printf("Listando midias playlist...");
                listarMidiasPlaylist(playlist);
                printf("\nPressione ENTER para voltar: ");
                getchar();
                scanf("%*c");
                break;
        }
    } while (opcao != 4);
}

void opcoesAlbumPublico(Album* album, Usuario** usuarioLogado) {
    int opcao, id;

    do {
        imprimeMenuOpcoesAlbumPublico();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\nReproduzindo midias do album: %s", pegaNomeAlbum(album));
                printf("\nPressione ENTER para voltar...");
                getchar();
                scanf("%*c");
                break;

            case 2:
                printf("Listando midias album...");
                imprimirMidiasAlbum(album);
                printf("\nPressione ENTER para voltar: ");
                getchar();
                scanf("%*c");
                break;
        }
    } while (opcao != 3);
}

void menuGerenciarMinhasPlaylists(Usuario** usuarioLogado) {
    int opcao;

    do {
        imprimeMenuGerenciarPlaylistsUsuario();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerPlaylist(usuarioLogado);
                *usuarioLogado = buscarUsuario(pegaIdUsuario(*usuarioLogado));
                break;

            case 2:
                printf("\nListando suas playlists...");
                listarPlaylistsUsuario(*usuarioLogado);
                int id;
                printf("\nDigite o id da playlist ou 0 para voltar: ");
                scanf("%d", &id);
                if (id) opcoesPlaylistDono(buscarPlaylist(id), usuarioLogado);
                break;
        }
    } while (opcao != 3);
}

void opcoesUsuarioPublico(Usuario** usuarioLogado) {
    int opcao, id, excluiu = 0;
    char nome[50], senha[15];

    do {
        imprimeMenuOpcoesPerfil();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Seu nome atual eh: %s", pegaNomeUsuario(*usuarioLogado));
                printf("\nDigite seu novo nome: ");
                scanf("%s", nome);
                modificaNomeUsuario(*usuarioLogado, nome);
                atualizarArquivoUsuarios(*usuarioLogado);
                break;

            case 2:
                printf("Sua senha atual eh: %s", pegaSenhaUsuario(*usuarioLogado));
                printf("\nDigite sua nova senha: ");
                scanf("%s", senha);
                modificaSenhaUsuario(*usuarioLogado, senha);
                atualizarArquivoUsuarios(*usuarioLogado);
                break;

            case 3:
                excluiu = excluirUsuario(*usuarioLogado);
                if (excluiu) {
                    printf("\nUsuario deletado com sucesso, o programa sera fechado.");
                    printf("\nPressione ENTER para continuar...");
                    getchar();
                    scanf("%*c");
                    exit(0);
                }
                break;
        }
    } while (opcao != 4);
}
