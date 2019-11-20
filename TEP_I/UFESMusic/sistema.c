#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "sistema.h"

struct sistema
{
    int qtdMidiasCadastradas;
    int qtdAlbunsCadastrados;
    int qtdPlaylistsCadastradas;
    int qtdUsuariosCadastrados;
    Usuario* usuarioLogado;
};


Sistema* inicializaSistema(int qtdMidiasCad, int qtdAlbunsCad, int qtdPlaylistsCad, int qtdUsuariosCad, Usuario* usuarioLogado){
    Sistema* sistema = alocarSistema(1);

    sistema->qtdMidiasCadastradas = qtdMidiasCad;
    sistema->qtdAlbunsCadastrados = qtdAlbunsCad;
    sistema->qtdPlaylistsCadastradas = qtdPlaylistsCad;
    sistema->qtdUsuariosCadastrados = qtdUsuariosCad;
    sistema->usuarioLogado = usuarioLogado;

    return sistema;
}

Sistema* alocarSistema(int qtd){
    Sistema* s = (Sistema*) malloc(sizeof(Sistema) * qtd);
    if (s == NULL)
    {
        printf("\nNao foi possivel alocar espaco para sistema!");
        getchar();
        scanf("%*c");
    }
    return s;
}

int pegaQtdMidiasCadastradas(Sistema* sistema){
    return sistema->qtdMidiasCadastradas;
}

int pegaQtdAlbunsCadastradas(Sistema* sistema){
    return sistema->qtdAlbunsCadastrados;
}

int pegaQtdPlaylistsCadastradas(Sistema* sistema){
    return sistema->qtdPlaylistsCadastradas;
}

int pegaQtdUsuariosCadastradas(Sistema* sistema){
    return sistema->qtdUsuariosCadastrados;
}

Usuario* pegaUsuarioLogado(Sistema* sistema){
    return sistema->usuarioLogado;
}

void modificaQtdMidiasCadastradas(Sistema* sistema, int nQtdMidiasCad){
    sistema->qtdMidiasCadastradas = nQtdMidiasCad;
}

void modificaQtdAlbunsCadastradas(Sistema* sistema, int nQtdAlbunsCad){
    sistema->qtdAlbunsCadastrados = nQtdAlbunsCad;
}

void modificaQtdPlaylistsCadastradas(Sistema* sistema, int nQtdPlaylistsCad){
    sistema->qtdPlaylistsCadastradas = nQtdPlaylistsCad;
}

void modificaQtdUsuariosCadastradas(Sistema* sistema, int nQtdUsuariosCad){
    sistema->qtdUsuariosCadastrados = nQtdUsuariosCad;
}

void modificaUsuarioLogado(Sistema* sistema, Usuario* nUsuario){
    sistema->usuarioLogado = nUsuario;
}
