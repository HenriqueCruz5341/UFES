#ifndef SISTEMA_H
#define SISTEMA_H
#include "usuario.h"

typedef struct sistema Sistema;

Sistema* inicializaSistema(int qtdMidiasCad, int qtdAlbunsCad, int qtdPlaylistsCad, int qtdUsuariosCad, Usuario* usuarioLogado);

Sistema* alocarSistema(int qtd);

int pegaQtdMidiasCadastradas(Sistema* sistema);

int pegaQtdAlbunsCadastradas(Sistema* sistema);

int pegaQtdPlaylistsCadastradas(Sistema* sistema);

int pegaQtdUsuariosCadastradas(Sistema* sistema);

Usuario* pegaUsuarioLogado(Sistema* sistema);

void modificaQtdMidiasCadastradas(Sistema* sistema, int nQtdMidiasCad);

void modificaQtdAlbunsCadastradas(Sistema* sistema, int nQtdAlbunsCad);

void modificaQtdPlaylistsCadastradas(Sistema* sistema, int nQtdPlaylistsCad);

void modificaQtdUsuariosCadastradas(Sistema* sistema, int nQtdUsuariosCad);

void modificaUsuarioLogado(Sistema* sistema, Usuario* nUsuario);

#endif