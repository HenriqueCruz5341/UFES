#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

struct sistema
{
    int qtdMidiasCadastradas;
    int qtdAlbunsCadastrados;
    int qtdPlaylistsCadastradas;
    int qtdUsuariosCadastrados;
    Usuario* usuarioLogado;
};
