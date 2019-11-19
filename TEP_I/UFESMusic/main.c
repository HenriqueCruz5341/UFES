#include <stdio.h>
#include "playlist.h"
#include "album.h"
#include "usuario.h"
#include "midia.h"
#include "impressoes.h"
#include <stdlib.h>
#include <string.h>

void fazerLogin();
void menuAdmin();
//void menuUsuario();

void gerenciarMidia();
void lerMidia(Album* album);
void opcoesMidiaAdmin(Midia* midia);
void selecionarMidia();
void menuListarTodasMidias();
void menuBuscarMidias();
int excluirMidia(Midia* midia);

void gerenciarPlaylst();
Playlist* lerPlaylist();
void selecionarPlaylist();
void menuListarTodasPlaylists();
void menuBuscarPlaylists();
void opcoesPlaylist(Playlist* playlist);
int excluirPlaylist(Playlist* playlist);

void gerenciarAlbuns();
Album* lerAlbum();
void selecionarAlbum();
void menuListarTodosAlbuns();
void menuBuscarAlbuns();
void opcoesAlbumAdmin(Album* album);
int excluirAlbum(Album* album);

void gerenciarUsuarios();
void lerUsuario(int verificador);
void selecionarUsuario();
void menuListarTodosUsuarios();
void menuBuscarUsuarios();
void opcoesUsuariosAdmin(Usuario* usuario);
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
    int op;
    printf("Digite 0 para menu normal ou 1 para menu admin: ");
    scanf("%d", &op);

    if (op) {
        menuAdmin();
        return;
    }
    //menuUsuario();
}

void menuAdmin() {
    int opcao;

    do {
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
                menuBuscarMidias();
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
    scanf("%d%*c", &qtdArtistas);
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
    adicionarMidiasAlbum(album, midia);
    salvarMidiaArquivo(midia);
}

void menuListarTodasMidias() {
    printf("\nListando todas as midias...");
    if (listarTodasMidias()) {
        selecionarMidia();
    } else {
        printf("\nArquivo de midias vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
    }
}

void selecionarMidia() {
    int id;
    printf("\nDigite o id da midia ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        opcoesMidiaAdmin(buscarMidia(id));
    }
}

void menuBuscarMidias() {
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
                selecionarMidia();
                break;

            case 2:
                printf("Digite o tipo da midia que deseja procurar: ");
                scanf("%d", &tipo);
                getchar();
                listarMidiasFiltro(2, string, tipo);
                selecionarMidia();
                break;

            case 3:
                printf("Digite o nome ou parte do nome do compositor da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(3, string, tipo);
                selecionarMidia();
                break;

            case 4:
                printf("Digite o nome ou parte do nome do artista da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(4, string, tipo);
                selecionarMidia();
                break;

            case 5:
                printf("Digite o genero ou parte do genero da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(5, string, tipo);
                selecionarMidia();
                break;

            case 6:
                printf("Digite a gravadora ou parte da gravadora da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(6, string, tipo);
                selecionarMidia();
                break;

            case 7:
                printf("Digite o album ou parte do album da midia que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarMidiasFiltro(7, string, tipo);
                selecionarMidia();
                break;

            case 8:
                menuListarTodasMidias();
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
                printf("O nome desse compositor atual da midia eh: %s", pegaCompositoresMidia(midia, indice-1));
                printf("\nDigite o novo compositor para a midia: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaCompositoresMidia(midia, nome, indice-1);
                atualizarArquivoMidias(midia);
                break;

            case 4:
                printf("Qual o indice do artista deseja alterar? ");
                scanf("%d", &indice);
                printf("O nome desse artista atual da midia eh: %s", pegaArtistasMidia(midia, indice-1));
                printf("\nDigite o novo artista para a midia: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaArtistasMidia(midia, nome, indice-1);
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

void gerenciarPlaylst(){
    int opcao;

    do {
        imprimeMenuGerenciarPlaylists();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lerPlaylist(NULL);
                break;

            case 2:
                menuListarTodasPlaylists();
                break;

            case 3:
                menuBuscarPlaylists();
                break;

        }
    } while (opcao != 4);
}

Playlist* lerPlaylist(Usuario* usuario){
    char nome[50];
    int privacidade, contribuintes[2], teraContribuinte;
    Playlist* playlist = alocarPlaylist(1);

    printf("Digite o nome da playlist: ");
    getchar();
    scanf("%[^\n]s", nome);
    printf("0 - Privada | 1 - Publica | 2 - Compartilhada");
    printf("\nDigite a privacidade da playlist: ");
    scanf("%d", &privacidade);
    if (usuario == NULL)
    {
        listarTodosUsuarios();
        printf("\nDigite o ID do usuario que sera o dono: ");
        scanf("%d", &contribuintes[0]);
    }
    if (privacidade == 2)
    {
        listarTodosUsuarios();
        printf("\nDigite o ID do usuario que sera um contribuinte da playlist: ");
        scanf("%d", &contribuintes[1]);
    }else   contribuintes[1] = 0;
    
    playlist = inicializaPlaylist(nome, privacidade, contribuintes);
    imprimePlaylist(playlist);
    salvarPlaylistArquivo(playlist);

    return playlist;
    
}

void selecionarPlaylist(){
    Playlist* playlist = alocarPlaylist(1);
    int id;
    printf("\nDigite o id da playlist ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        playlist = buscarPlaylist(id);
        opcoesPlaylist(buscarPlaylist(id));
    }
}

void menuListarTodasPlaylists(){
    printf("\nListando todas as playlists...");
    if (listarTodasPlaylists()) {
        selecionarPlaylist();
    } else {
        printf("\nArquivo de playlists vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
    }
}

void menuBuscarPlaylists(){

}

void opcoesPlaylist(Playlist* playlist){
    char nome[50];
    int opcaoMenu, excluiu, numero, contribuinte, id, pos;

    do {
        imprimeMenuOpcoesPlaylist();
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 1:
                printf("O nome atual da playlist eh: %s", pegaNomePlaylist(playlist));
                printf("\nDigite o novo nome para a playlist: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaNomePlaylist(playlist, nome);
                atualizarArquivoPlaylists(playlist);
                break;

            case 2:
                printf("0 - Privada | 1 - Publica | 2 - Compartilhada");
                printf("\nA privacidade atual dessa playlist eh: %d", pegaPrivacidadePlaylist(playlist));
                printf("\nDigite o numero para a nova privacidade da playlist: ");
                scanf("%d", &numero);
                modificaPrivacidadePlaylist(playlist, numero);
                atualizarArquivoPlaylists(playlist);
                break;

            case 3:
                contribuinte = pegaContribuintesPlaylist(playlist)[1];
                if (contribuinte) printf("O colaborador atual da playlist eh: %s", pegaNomeUsuario(buscarUsuario(contribuinte)));
                else printf("A playlist nao possui contribuidor.");
                listarTodosUsuarios();
                printf("\nDigite o ID do usuario que sera o novo contribuinte da playlist: ");
                scanf("%d", &numero);
                modificaContribuintesPlaylist(playlist, numero);
                atualizarArquivoPlaylists(playlist);
                break;

            case 4:
                printf("Listando todas as midias.");
                listarTodasMidias();
                printf("\nDigite o id da midia para adicionar a playlist ou 0 para voltar: ");
                scanf("%d", &id);
                if(id)  adicionarMidiaPlaylist(playlist, buscarMidia(id));
                atualizarArquivoPlaylists(playlist);
                break;

            case 5:
                printf("Listando todas as midias.");
                listarMidiasPlaylist(playlist);
                printf("\nDigite o id da midia para remover da playlist ou 0 para voltar: ");
                scanf("%d", &id);
                if(id)  removerMidiaPlaylist(playlist, buscarMidia(id));
                atualizarArquivoPlaylists(playlist);
                break;

            case 6:
                printf("Listando todas as midias da playlist.");
                listarMidiasPlaylist(playlist);
                printf("\nDigite 0 para voltar: ");
                scanf("%d", &numero);
                break;

            case 7:
                printf("Listando todas as midias da playlist.");
                listarMidiasPlaylist(playlist);
                printf("\nDigite o id da midia que deseja alterar a posicao: ");
                scanf("%d", &id);
                printf("Digite a nova posicao que deseja colocar a midia: ");
                scanf("%d", &pos);
                trocarPosicaoMidiaPlaylist(playlist, buscarMidia(id), pos);
                atualizarArquivoPlaylists(playlist);
                break;

            case 8:
                excluiu = excluirPlaylist(playlist);
                if (excluiu) return;
                break;
        }

    } while (opcaoMenu != 9);
}

int excluirPlaylist(Playlist* playlist){
    int op;
    printf("Tem certeza que deseja excluir esta playlist? (0/1)");
    scanf("%d", &op);

    if (op) {
        excluirPlaylistArquivo(playlist);
        return 1;
    }
    return 0;
}

void gerenciarAlbuns() {
    int opcao;

    do {
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
                menuBuscarAlbuns();
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

void menuListarTodosAlbuns() {
    printf("\nListando todos os albuns...");
    if (listarTodosAlbuns()) {
        selecionarAlbum();
    } else {
        printf("\nArquivo de albuns vazio!");
        printf("\nPressione ENTER para voltar...");
        getchar();
        scanf("%*c");
    }
}

void selecionarAlbum() {
    Album* album = alocarAlbum(1);
    int id;
    printf("\nDigite o id do album ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        album = buscarAlbum(id);
        opcoesAlbumAdmin(buscarAlbum(id));
    }
}

void menuBuscarAlbuns() {
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
                selecionarAlbum();
                break;

            case 2:
                printf("Digite o nome ou parte do nome do participante que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(2, string, tipo);
                selecionarAlbum();
                break;

            case 3:
                printf("Digite a data de lancamento ou parte do album que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(3, string, tipo);
                selecionarAlbum();
                break;

            case 4:
                menuListarTodosAlbuns();
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
                printf("O nome desse participante atual do album eh: %s", pegaParticipantesAlbum(album, opcaoPart-1));
                printf("\nDigite o novo participante para o album: ");
                getchar();
                scanf("%[^\n]s", nome);
                modificaParticipantesAlbum(album, nome, opcaoPart-1);
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
                imprimirMidiasAlbum(album);
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

void gerenciarUsuarios(){
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

void selecionarUsuario(){
    Usuario* usuario = alocarUsuario(1);
    int id;
    printf("\nDigite o id do usuaro ou 0 para voltar: ");
    scanf("%d", &id);

    if (id) {
        usuario = buscarUsuario(id);
        opcoesUsuariosAdmin(usuario);
    }
}

void menuListarTodosUsuarios(){
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

void menuBuscarUsuarios(){
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

void opcoesUsuariosAdmin(Usuario* usuario){
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
                //listarPlaylistsUsuario(usuario);
                break;

            case 5:
                excluiu = excluirUsuario(usuario);
                if (excluiu) return;
                break;
        }

    } while (opcaoMenu != 6);
}

int excluirUsuario(Usuario* usuario){
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