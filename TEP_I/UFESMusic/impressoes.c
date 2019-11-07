#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

void imprimeMenuPrincipal() {
    printf("======| BEM-VINDO AO UFES MUSIC |======\n");
    printf("1 - Fazer login.\n");
    printf("2 - Cadastrar-se.\n");
    printf("3 - Sair.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuOpcoesAdmin() {
    printf("======| MENU OPCOES ADMIN |======\n");
    printf("1 - Gerenciar midias.\n");
    printf("2 - Gerenciar playlists.\n");
    printf("3 - Gerenciar albuns.\n");
    printf("4 - Gerenciar usuarios.\n");
    printf("5 - Logout.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuGerenciarMidia() {
    printf("======| MENU GERENCIAR MIDIAS |======\n");
    printf("1 - Adicionar nova midia.\n");
    printf("2 - Listar todas as midias.\n");
    printf("3 - Buscar midia.\n");
    printf("4 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuGerenciarPlaylists() {
    printf("======| MENU GERENCIAR PLAYLISTS |======\n");
    printf("1 - Criar nova playlist.\n");
    printf("2 - Listar todas as playlists.\n");
    printf("3 - Buscar playlist.\n");
    printf("4 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuGerenciarAlbuns() {
    printf("======| MENU GERENCIAR ALBUNS |======\n");
    printf("1 - Criar novo album.\n");
    printf("2 - Listar todos os albuns.\n");
    printf("3 - Buscar album.\n");
    printf("4 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuGerenciarUsuarios() {
    printf("======| MENU GERENCIAR USUARIOS |======\n");
    printf("1 - Criar novo usuario.\n");
    printf("2 - Listar todos os usuarios.\n");
    printf("3 - Buscar usuario.\n");
    printf("4 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuOpcoesUsuario() {
    printf("======| MENU OPCOES USUARIO |======\n");
    printf("1 - Buscar midias.\n");
    printf("2 - Buscar playlists.\n");
    printf("3 - Gerenciar minhas playlists.\n");
    printf("4 - Editar perfil.\n");
    printf("5 - Sair.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuBuscarMidias() {
    printf("======| MENU BUSCAR MIDIAS |======\n");
    printf("1 - Filtrar por nome.\n");
    printf("2 - Filtrar por tipo.\n");
    printf("3 - Filtrar por compositor.\n");
    printf("4 - Filtrar por artista.\n");
    printf("5 - Filtrar por genero.\n");
    printf("6 - Filtrar por gravadora.\n");
    printf("7 - Filtrar por album.\n");
    printf("8 - Todas as midias.\n");
    printf("9 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuBuscarAlbuns() {
    printf("======| MENU BUSCAR ALBUNS |======\n");
    printf("1 - Filtrar por nome.\n");
    printf("2 - Filtrar por participante.\n");
    printf("3 - Filtrar por data de lancamento.\n");
    printf("4 - Todas as midias.\n");
    printf("5 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuOpcoesPerfil() {
    printf("======| MENU OPCOES PERFIL |======\n");
    printf("1 - Trocar nome.\n");
    printf("2 - Trocar senha.\n");
    printf("3 - Deletar conta.\n");
    printf("4 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuOpcoesMidiaAdmin() {
    printf("======| MENU EDICAO MIDIA |======\n");
    printf("1 - Trocar nome.\n");
    printf("2 - Trocar tipo.\n");
    printf("3 - Trocar compositores.\n");
    printf("4 - Trocar artistas.\n");
    printf("5 - Trocar genero.\n");
    printf("6 - Trocar gravadora.\n");
    printf("7 - Trocar duracao.\n");
    printf("8 - Excluir midia.\n");
    printf("9 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}

void imprimeMenuOpcoesAlbumAdmin() {
    printf("======| MENU EDICAO ALBUM |======\n");
    printf("1 - Trocar nome.\n");
    printf("2 - Trocar participantes.\n");
    printf("3 - Trocar data de lancamento.\n");
    printf("4 - Adicionar midia.\n");
    printf("5 - Listar midias do album.\n");
    printf("6 - Voltar.\n");
    printf("Digite o numero da opcao desejada: ");
}