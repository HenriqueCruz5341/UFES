#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include <string.h>
#include "playlist.h"

struct usuario {
    int idUsuario;
    char nome[50];
    int tipo; // Normal = 0, Admin = 1
    char senha[15];
    int qtdPlaylists;
    int playlists[20]; // podem ser playlists onde esse usuario eh dono, contribuinte ou seguidor
};

Usuario* inicializaUsuario(char* nome, int tipo, char* senha, int* playlists) {
    Usuario* usuario = (Usuario*) malloc(sizeof (Usuario));

    if (usuario == NULL) {
        printf("Erro ao fazer cadastro de usuario!");
        getchar();
        scanf("%*c");
        return usuario;
    }

    usuario->idUsuario = pegaUltimoIdUsuarioCadastrado() + 1;
    strcpy(usuario->nome, nome);
    usuario->tipo = tipo;
    strcpy(usuario->senha, senha);
    for (int i = 0; i < 20; i++) {
        usuario->playlists[i] = 0;
    }

    return usuario;
}

Usuario* alocarUsuario(int qtd) {
    Usuario* u = (Usuario*) malloc(sizeof (Usuario) * qtd);
    if (u == NULL) {
        printf("\nNao foi possivel alocar espaco para usuario!");
        getchar();
    }
    return u;
}

void modificaNomeUsuario(Usuario* usuario, char* nNome) {
    strcpy(usuario->nome, nNome);
}

void modificaTipoUsuario(Usuario* usuario, int nTipo) {
    usuario->tipo = nTipo;
}

void modificaSenhaUsuario(Usuario* usuario, char* nSenha) {
    strcpy(usuario->senha, nSenha);
}


void modificaQtdPlaylistsUsuario(Usuario* usuario, int nQtdPlaylists) {
    usuario->qtdPlaylists = nQtdPlaylists;
}

int pegaIdUsuario(Usuario* usuario) {
    return usuario->idUsuario;
}

char* pegaNomeUsuario(Usuario* usuario) {
    return usuario->nome;
}

int pegaTipoUsuario(Usuario* usuario) {
    return usuario->tipo;
}

char* pegaSenhaUsuario(Usuario* usuario) {
    return usuario->senha;
}

int* pegaPlaylistsUsuario(Usuario* usuario) {
    return usuario->playlists;
}

int pegaQtdPlaylistsUsuario(Usuario* usuario) {
    return usuario->qtdPlaylists;
}

void imprimeUsuario(Usuario* usuario) {
    printf("\nID: %d", pegaIdUsuario(usuario));
    printf("\nNome: %s", pegaNomeUsuario(usuario));
    printf("\nSenha: %s", pegaSenhaUsuario(usuario));
    printf("\nQtd playlists: %d", pegaQtdPlaylistsUsuario(usuario));
    int tipo = pegaTipoUsuario(usuario);
    if (tipo) {
        printf("\nTipo: Administrador");
    } else {
        printf("\nTipo: Normal");
    }
}

void destroiUsuario(Usuario* usuario) {
    if (usuario != NULL) {
        free(usuario);
    }
}

void salvarUsuarioArquivo(Usuario* usuario) {
    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "ab")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return;
    }

    fwrite(usuario, sizeof (Usuario), 1, arqUsuarios);

    fclose(arqUsuarios);
}

int pegaUltimoIdUsuarioCadastrado() {
    Usuario* usuario = alocarUsuario(1);
    int ultimoId;

    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        return 0;
    }

    while (fread(usuario, sizeof (Usuario), 1, arqUsuarios) == 1);
    ultimoId = pegaIdUsuario(usuario);

    destroiUsuario(usuario);
    fclose(arqUsuarios);

    return ultimoId;
}

Usuario* buscarUsuario(int idUsuario) {
    Usuario* usuario = alocarUsuario(1);

    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return NULL;
    }

    while (fread(usuario, sizeof (Usuario), 1, arqUsuarios) == 1 && pegaIdUsuario(usuario) != idUsuario);

    fclose(arqUsuarios);

    return usuario;
}

int listarTodosUsuarios() {
    Usuario* usuario = alocarUsuario(1);

    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return 0;
    }

    while (fread(usuario, sizeof (Usuario), 1, arqUsuarios) == 1) {
        imprimeUsuario(usuario);
        printf("\n----------");
    }

    fclose(arqUsuarios);

    return 1;
}

int quantidadeUsuariosCadastrados() {
    Usuario* usuario = alocarUsuario(1);
    int i = 0;
    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return 0;
    }

    while (fread(usuario, sizeof (Usuario), 1, arqUsuarios) == 1) i++;

    fclose(arqUsuarios);
    destroiUsuario(usuario);

    return i;
}

void excluirUsuarioArquivo(Usuario* usuario) {
    int qtdUsuarios = quantidadeUsuariosCadastrados(), removeu = 0, *playlistsUsuario, j = 0, idUsuarioRemovido = 0;
    Usuario* listaUsuarios = alocarUsuario(qtdUsuarios);
    Usuario* usuarioAux = alocarUsuario(1);
    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return;
    }

    for (int i = 0; i < qtdUsuarios; i++) {
        fread(usuarioAux, sizeof (Usuario), 1, arqUsuarios);
        if (pegaIdUsuario(usuarioAux) == pegaIdUsuario(usuario)) {
            removeu = 1;
        } else if (removeu) {
            listaUsuarios[i - 1] = *usuarioAux;
        } else {
            listaUsuarios[i] = *usuarioAux;
        }
    }

    fclose(arqUsuarios);
    destroiUsuario(usuarioAux);

    if ((arqUsuarios = fopen("usuarios.dat", "wb")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return;
    }

    fwrite(listaUsuarios, sizeof (Usuario), qtdUsuarios - 1, arqUsuarios);

    destroiUsuario(listaUsuarios);
    fclose(arqUsuarios);
    removerTodasPlaylistsUsuario(pegaPlaylistsUsuario(usuario), pegaIdUsuario(usuario));
    destroiUsuario(usuario);
}

void removerTodasPlaylistsUsuario(int* playlists, int idUsuario) {
    int j = 0;

    while (playlists[j]) {
        Playlist* p = buscarPlaylist(playlists[j]);
        if (idUsuario == pegaContribuintesPlaylist(p)[0]) {
            removerPlaylistTodosUsuario(playlists[j]);
            excluirPlaylistArquivo(p);
        }
        j++;
        destroiPlaylist(p);
    }
}

void atualizarArquivoUsuarios(Usuario* usuario) {
    int i = 0;
    Usuario* usuarioAux = alocarUsuario(1);
    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "r+b")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return;
    }

    while (fread(usuarioAux, sizeof (Usuario), 1, arqUsuarios) == 1 && pegaIdUsuario(usuarioAux) != pegaIdUsuario(usuario))
        i++;

    fseek(arqUsuarios, i * sizeof (Usuario), SEEK_SET);

    fwrite(usuario, sizeof (Usuario), 1, arqUsuarios);

    destroiUsuario(usuarioAux);
    fclose(arqUsuarios);
}

void listarUsuariosFiltro(int tipoFiltro, char* string, int numero) {
    FILE* arqUsuarios;
    Usuario* usuario = alocarUsuario(1);
    char* stringAux = NULL;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        printf("\nAinda nao possuem usuarios cadastradas!");
        getchar();
        scanf("%*c");
        return;
    }

    printf("\nListando usuarios encontradas...");

    switch (tipoFiltro) {
        case 1:
            while (fread(usuario, sizeof (Usuario), 1, arqUsuarios) == 1) {
                stringAux = strstr(pegaNomeUsuario(usuario), string);
                if (stringAux) {
                    imprimeUsuario(usuario);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;

        case 2:
            while (fread(usuario, sizeof (Usuario), 1, arqUsuarios) == 1) {
                if (pegaTipoUsuario(usuario) == numero) {
                    imprimeUsuario(usuario);
                    printf("\n-----------");
                    stringAux = NULL;
                }
            }
            break;
    }

    fclose(arqUsuarios);
    destroiUsuario(usuario);
}

Usuario* autenticarUsuario(char* nome, char* senha) {
    Usuario* usuarioAux = alocarUsuario(1);
    FILE* arqUsuarios;
    int achou = 0;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return NULL;
    }

    while (fread(usuarioAux, sizeof (Usuario), 1, arqUsuarios)) {
        if (!strcmp(pegaNomeUsuario(usuarioAux), nome) && !strcmp(pegaSenhaUsuario(usuarioAux), senha)) {
            achou = 1;
            break;
        }
    }

    fclose(arqUsuarios);
    if (achou) return usuarioAux;
    else return NULL;
}

void listarPlaylistsUsuario(Usuario* usuario) {
    int qtdPlaylists = pegaQtdPlaylistsUsuario(usuario);

    for (int i = 0; i < qtdPlaylists; i++) {
        imprimePlaylist(buscarPlaylist(usuario->playlists[i]));
        printf("\n-----------");
    }
}

void adicionarPlaylistUsuario(Usuario* usuario, Playlist* playlist) {
    int pos = pegaQtdPlaylistsUsuario(usuario);

    usuario->playlists[pos] = pegaIdPlaylist(playlist);
    modificaQtdPlaylistsUsuario(usuario, pos + 1);
    atualizarArquivoUsuarios(usuario);
}

void removerPlaylistTodosUsuario(int idPlaylist) {
    int pos = 0, excluiu = 0;
    Usuario* usuario = alocarUsuario(1);
    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL) {
        printf("Erro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return;
    }

    while (fread(usuario, sizeof (Usuario), 1, arqUsuarios) == 1) {
        int* vetPlaylists = pegaPlaylistsUsuario(usuario);
        int qtdPlaylistsUsuario = pegaQtdPlaylistsUsuario(usuario);
        excluiu = 0;
        for (pos = 0; pos < qtdPlaylistsUsuario; pos++) {
            if (excluiu) {
                vetPlaylists[pos - 1] = vetPlaylists[pos];
                vetPlaylists[pos] = 0;
            }
            if (vetPlaylists[pos] == idPlaylist) {
                vetPlaylists[pos] = 0;
                excluiu = 1;
            }
        }
        if (excluiu) {
            modificaQtdPlaylistsUsuario(usuario, qtdPlaylistsUsuario - 1);
            atualizarArquivoUsuarios(usuario);
        }
    }
    destroiUsuario(usuario);
    fclose(arqUsuarios);
}