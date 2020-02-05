#include <stdio.h>
#include "playlist.h"
#include "album.h"
#include "usuario.h"
#include "midia.h"
#include "impressoes.h"
#include <stdlib.h>
#include <string.h>

/*Faz a autenticação de um usuario que deseja logar
* pre-condicao: tenha algum usuario cadastrado no sistema
* pos-condicao: o usuario sera levado ate o menu para gerenciar sua conta  
*/
void fazerLogin();

/*Mostra o menu de opçoes quando o usuario logado é do tipo Admin
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter conseguido logar e ele ser do tipo Admin
* pos-condicao: dependendo da opção que o usuario escolher, sera redirecionado para um menu diferente
*/
void menuAdmin(Usuario** usuarioLogado);

/*Mostra o menu de opções quando o usuario logado é do tipo Normal
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter conseguido logar e ele ser do tipo Normal
* pos-condicao: dependendo da opção que o usuario escolher, sera redirecionado para um menu diferente  
*/
void menuUsuario(Usuario** usuarioLogado);


/*Mostra o menu de opções que um usuario do tipo Admin pode fazer com o tipo midia
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario do tipo Admin deve ter escolhido a opção de gerenciar midias no menu anteriors
* pos-condicao: dependendo da opção que o usuario escolher, sera redirecionado para um menu diferente  
*/
void gerenciarMidia(Usuario** usuarioLogado);

/*Cadastra uma nova midia no sistema
* inputs: um ponteiro para album, caso essa função tenha sido chamada para adicionar uma midia a um album, o ponteiro de album tera o album no qual a midia pertencerá, 
caso a função tenha sido chamada apenas para criar uma nova midia, o ponteiro de album sera nulo e durante a criacao, serao dadas as opções de albuns
* pre-condicao: o usuario do tipo Admin deve ter escolhido a opção de criar uma nova midia
* pos-condicao: uma nova midia sera cadastrada no arquivo de midias, e o arquivo de albuns sera atualizado
*/
void lerMidia(Album* album);

/*Mostra o menu de opções que um usuario do tipo Admin pode fazer com uma midia
* inputs: um ponteiro para a midia que o Admin poderá realizar as operações
* pre-condicao: o Admin deve ter selecionado uma midia cadastrada no sistema, o usuario logado deve ser do tipo Admin
* pos-condicao: dependendo da opção que o Admin escolher, será realizado alguma operação com a midia em questão
*/
void opcoesMidiaAdmin(Midia* midia);

/*Mostra o menu de opções que um usuario do tipo Normal pode fazer com uma midia
* inputs: um ponteiro para a midia que o usuario poderá realizar as operações
* pre-condicao: o usuario deve ter selecionado uma midia cadastrada no sistema, o usuario logado deve ser do tipo Normal
* pos-condicao: dependendo da opção que o usuario escolher, será realizado alguma operação com a midia em questão
*/
void opcoesMidiaPublico(Midia* midia, Usuario** usuarioLogado);

/*Le o ID da midia que foi selecionada e chama a função para mostrar as opções da midia desejada
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter pedido para listar as midias, seja por filtro ou todas as midias
* pos-condicao: envia a midia que foi selecionada para a função de opções dessa midia, dependendo do tipo de usuario que esta logado
*/
void selecionarMidia(Usuario** usuarioLogado);

/*Função para imprimir todas as midias cadastradas, caso haja alguma
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter selecionado uma opção de listar todas as midias
* pos-condicao: caso tenha midias cadastradas, todas serao listadas
*/
void menuListarTodasMidias(Usuario** usuarioLogado);

/*Mostra o menu de opções de filtro que o usuario tem na hora de buscar midias
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter selecionado uma opção de buscar midias
* pos-condicao: dependendo do filtro que o usuario escolher, as midias encontradas serão listadas
*/
void menuBuscarMidias(Usuario** usuarioLogado);

/*Exclui uma midia do sistema
* inputs: um ponteiro para a midia que sera excluida
* pre-condicao: o Admin deve ter selecionado uma midia valida
* pos-condicao: a midia é excluida do sistema  
*/
int excluirMidia(Midia* midia);


/*Mostra o menu de opções que o Admin pode fazer com o tipo playlist
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario do tipo Admin deve ter escolhido a opção de gerenciar playlists no menu anteriors
* pos-condicao: dependendo da opção que o usuario escolher, sera redirecionado para um menu diferente  
*/
void gerenciarPlaylst(Usuario** usuarioLogado);

/*Mostra o menu de opções que um usuario consegue realizar com as playlists que ele segue, é dono ou colaborador
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario do tipo normal deve ter escolhido a opção de gerenciar suas playlists
* pos-condicao: dependendo da opção que o usuario escolher, sera redirecionado para um menu diferente
*/
void menuGerenciarMinhasPlaylists(Usuario** usuarioLogado);

/*Cadastra uma nova playlist no sistema
* inputs: caso ja se saiba qual usuario será o dono da playlist, esse mesmo usuario sera passado por parametro,
caso nao tenha isso definido, deve ser passado NULL para que seja possivel colocar um dono no decorrer da função
* outputs: retorna a playlist que foi criada
* pre-condicao: o usuario que esta logado, deverá clicar na opção de criar uma nova playlist
* pos-condicao: uma nova playlist sera criada no sistema, e o arquivo de usuarios sera atualizado
*/
Playlist* lerPlaylist(Usuario** usuario);

/*Le o ID da playlist que foi selecionada e chama a função para mostrar as opções da playlist desejada
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter pedido para listar as playlist, seja por filtro ou todas as playlists
* pos-condicao: envia a playlist que foi selecionada para a função de opções dessa playlist, dependendo do tipo de usuario que esta logado
*/
void selecionarPlaylist(Usuario** usuarioLogado);

/*Função para imprimir todas as playlists cadastradas, caso haja alguma
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter selecionado uma opção de listar todas as playlists
* pos-condicao: caso tenha playlists cadastradas, todas serao listadas
*/
void menuListarTodasPlaylists(Usuario** usuarioLogado);

/*Mostra o menu de opções de filtro que o usuario tem na hora de buscar playlists
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter selecionado uma opção de buscar playlists
* pos-condicao: dependendo do filtro que o usuario escolher, as playlists encontradas serão listadas  
*/
void menuBuscarPlaylists(Usuario** usuarioLogado);

/*Mostra o menu de opções que um usuario uma playlist, caso o usuario seja o dono ou um Admin, ele terá todas 
as opções 'desbloqueadas', caso seja um colaborador, apenas algumas, e caso seja um seguidor da playlist, podera apenas ver as midias que estão na playlist
* inputs: um ponteiro para a playlist que o usuario poderá realizar as operações, e um ponteiro do usuario logado,
para saber quais opções estarão 'desbloqueadas' para o mesmo
* pre-condicao: o usuario deve ter selecionado uma plyalist cadastrada no sistema
* pos-condicao: dependendo da opção que o usuario escolher, será realizado alguma operação com a playlist em questão
*/
void opcoesPlaylistDono(Playlist* playlist, Usuario** usuarioLogado);

/*Mostra o menu de opções que um usuario do tipo Normal e que não segue a playlist pode fazer com uma playlist
* inputs: um ponteiro para a playlist que o usuario poderá realizar as operações,
e um ponteiro indicando qual usuario esta logado, para caso o mesmo queira começar a seguir a playlist selecionada
* pre-condicao: o usuario deve ter selecionado uma midia cadastrada no sistema, e não ter escolhido a opção 
'gerenciar minhas playlists' anteriormente
* pos-condicao: dependendo da opção que o usuario escolher, será realizado alguma operação com a midia em questão, e caso
o usuario tenha seguido a playlist, o arquivo de usuarios e o usuarioLogado sera atualizado
*/
void opcoesPlaylistPublico(Playlist* playlist, Usuario** usuarioLogado);

/*Exclui uma playlist do sistema
* inputs: um ponteiro para a playlist que sera excluida
* pre-condicao: o Admin ou o usuario dono deve ter selecionado uma playlist valida
* pos-condicao: a playlist é excluida do sistema
*/
int excluirPlaylist(Playlist* playlist);


/*Mostra o menu de opções que o Admin pode fazer com o tipo album
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario do tipo Admin deve ter escolhido a opção de gerenciar albuns no menu anterior
* pos-condicao: dependendo da opção que o usuario escolher, sera redirecionado para um menu diferente
*/
void gerenciarAlbuns(Usuario** usuarioLogado);

/*Cadastra um novo album no sistema
* outputs: retorna o album que foi cadastrado no sistema
* pre-condicao: o usuario do tipo Admin deve ter escolhido a opção de criar um novo album
* pos-condicao: um novo album sera cadastrada no arquivo de albuns
*/
Album* lerAlbum();

/*Le o ID do album que foi selecionado e chama a função para mostrar as opções do album desejado
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter pedido para listar os albuns, seja por filtro ou todos os albuns
* pos-condicao: envia o album que foi selecionado para a função de opções desse album, dependendo do tipo de usuario que esta logado
*/
void selecionarAlbum(Usuario** usuarioLogado);

/*Função para imprimir todos os albuns cadastradas, caso haja algum
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter selecionado uma opção de listar todos os albuns
* pos-condicao: caso tenha albuns cadastrados, todas serao listadas
*/
void menuListarTodosAlbuns(Usuario** usuarioLogado);

/*Mostra o menu de opções de filtro que o usuario tem na hora de buscar albuns
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario deve ter selecionado uma opção de buscar albuns
* pos-condicao: dependendo do filtro que o usuario escolher, os albuns encontrados serão listadas
*/
void menuBuscarAlbuns(Usuario** usuarioLogado);

/*Mostra o menu de opções que um usuario do tipo Admin pode fazer com um album
* inputs: um ponteiro para o album que o Admin poderá realizar as operações
* pre-condicao: o Admin deve ter selecionado um album cadastrado no sistema, o usuario logado deve ser do tipo Admin
* pos-condicao: dependendo da opção que o Admin escolher, será realizado alguma operação com o album em questão
*/
void opcoesAlbumAdmin(Album* album);

/*Mostra o menu de opções que um usuario do tipo Normal pode fazer com um album
* inputs: um ponteiro para o album que o usuario poderá realizar as operações
* pre-condicao: o usuario deve ter selecionado um album cadastrado no sistema, o usuario logado deve ser do tipo Normal
* pos-condicao: dependendo da opção que o usuario escolher, será realizado alguma operação com o album em questão
*/
void opcoesAlbumPublico(Album* album, Usuario** usuarioLogado);

/*Exclui um album do sistema, e todas as midias que pertenciam aquele album
* inputs: um ponteiro para o album que sera excluida
* pre-condicao: o Admin deve ter selecionado um album valido
* pos-condicao: a midia é excluida do sistema, assim como todas as midias que pertenciam aquele album
*/
int excluirAlbum(Album* album);


/*Mostra o menu de opções que um usuario do tipo Admin pode fazer com o tipo usuario
* inputs: o usuario que esta atualmente logado no sistema
* pre-condicao: o usuario do tipo Admin deve ter escolhido a opção de gerenciar usuarios no menu anteriors
* pos-condicao: dependendo da opção que o usuario escolher, sera redirecionado para um menu diferente  
*/
void gerenciarUsuarios();

/*Cadastra um novo usuario no sistema
* inputs: um inteiro que ira diferenciar se a criacao esta vindo de um cadastro normal, ou é um Admin adicionando um outro usuario,
caso seja a primeira opção esse parametro será 0, caso contrario, sera 1
* pre-condicao: o usuario deve ter escolhido a opção de se cadastrar, ou um Admin deve ter escolhido a opção de inserir
um novo usuario
* pos-condicao: um novo usuario do tipo Normal ou Admin sera adicionado no sistema
*/
void lerUsuario(int verificador);

/*Le o ID da usuario que foi selecionada e chama a função para mostrar as opções do usuario desejado
* pre-condicao: o Admin deve ter pedido para listar os usuarios cadastrados, seja por filtro ou todaos os usuarios
* pos-condicao: envia o usuario que foi selecionado para a função de opções desse usuario, dependendo do tipo de usuario que esta logado
*/
void selecionarUsuario();

/*Função para imprimir todas os usuarios cadastrados
* pre-condicao: o Admin deve ter selecionado uma opção de listar todos os usuarios
* pos-condicao: todos os usuarios cadastrados no sistema serao listados
*/
void menuListarTodosUsuarios();

/*Mostra o menu de opções de filtro que o Admin tem na hora de buscar usuarios
* pre-condicao: o usuario deve ter selecionado uma opção de buscar midias
* pos-condicao: dependendo do filtro que o Admin escolher, os usuarios encontrados serao listados
*/
void menuBuscarUsuarios();

/*Mostra o menu de opções que o Admin pode fazer com um usuario
* inputs: um ponteiro para o usuario que o Admin poderá realizar as operações
* pre-condicao: o Admin deve ter selecionado um usuario cadastrada no sistema
* pos-condicao: dependendo da opção que o Admin escolher, será realizado alguma operação com o usuario em questão
*/
void opcoesUsuariosAdmin(Usuario* usuario);

/*Mostra o menu de opções para que o usuario possa modificar seu perfil
* inputs: um ponteiro para o usuario logado para saber qual usuario sera editado
* pre-condicao: o usuario deve ter escolhido a opção de editar seu perfil
* pos-condicao: dependendo da opção que o usuario escolher, sera realizada alguma operação com o usuario
*/
void opcoesUsuarioPublico(Usuario** usuarioLogado);

/*Exclui um usuario do sistema
* inputs: um ponteiro para o usuario que sera excluido
* pre-condicao: o Admin deve ter selecionado a opção de excluir um usuario, ou um usuario deve escolher a opção de 
deletar sua propria conta
* pos-condicao: o usuario é excluido no sistema
*/
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
    //Caso queira cadastrar um admin descomentar essa parte
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
    destroiUsuario(usuarioLogado);
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
    printf("Digite o tipo de midia (0 musica, 1 video, 2 podcast): ");
    scanf("%d", &tipo);
    printf("Digite quantos compositores a midia possui: ");
    scanf("%d", &qtdCompositores);
    for (i = 0; i < qtdCompositores; i++) {
        printf("Digite o compositor %d: ", i + 1);
        getchar();
        scanf("%[^\n]s", compositores[i]);
    }
    for (i; i < 3; i++) {
        compositores[i][0] = '\0';
    }
    printf("Digite quantos artistas a midia possui: ");
    scanf("%d", &qtdArtistas);
    for (i = 0; i < qtdArtistas; i++) {
        printf("Digite o artista %d: ", i + 1);
        getchar();
        scanf("%[^\n]s", artistas[i]);
    }
    for (i; i < 3; i++) {
        artistas[i][0] = '\0';
    }
    printf("Digite o genero da midia: ");
    scanf("%s%*c", genero);
    printf("Digite a gravadora da midia: ");
    scanf("%[^\n]s", gravadora);
    printf("Digite a duracao da midia (MM:SS): ");
    scanf("%s", duracao);
    if (album == NULL) {
        printf("Escolha o album a qual a midia pertence: ");
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
    if(usuario) *usuario = buscarUsuario(contribuintes[0]);
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
                        modificaContribuintePlaylist(playlist, numero);
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
                if (pegaTipoUsuario(*usuarioLogado) || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[0] || pegaIdUsuario(*usuarioLogado) == pegaContribuintesPlaylist(playlist)[1]) {
                    printf("Listando todas as midias.");
                    listarMidiasPlaylist(playlist);
                    printf("\nDigite o id da midia para remover da playlist ou 0 para voltar: ");
                    scanf("%d", &id);
                    if (id) removerMidiaPlaylist(playlist, buscarMidia(id));
                    atualizarArquivoPlaylists(playlist);
                }
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
                    if (excluiu) {
                        *usuarioLogado = buscarUsuario(pegaIdUsuario(*usuarioLogado));
                        return;
                    }
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
    printf("Digite a quantidade de participantes do album: ");
    scanf("%d", &qtdParticipantes);
    for (i = 0; i < qtdParticipantes; i++) {
        printf("Digite o participante %d: ", i + 1);
        getchar();
        scanf("%[^\n]s", particiapantes[i]);
    }
    for (i; i < 3; i++) {
        particiapantes[i][0] = '\0';
    }
    printf("Digite a data de lancamento do album (DD/MM/AAAA): ");
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

    do {
        imprimeMenuBuscarAlbuns();
        scanf("%d", &opcaoMenu);
        getchar();
        switch (opcaoMenu) {
            case 1:
                printf("Digite o nome ou parte do nome do album que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(1, string);
                selecionarAlbum(usuarioLogado);
                break;

            case 2:
                printf("Digite o nome ou parte do nome do participante que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(2, string);
                selecionarAlbum(usuarioLogado);
                break;

            case 3:
                printf("Digite a data de lancamento ou parte do album que deseja procurar: ");
                scanf("%[^\n]s", string);
                getchar();
                listarAlbunsFiltro(3, string);
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
