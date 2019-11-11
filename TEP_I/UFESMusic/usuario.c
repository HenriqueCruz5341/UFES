#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include <string.h>

struct usuario
{
    int idUsuario;
    char nome[50];
    int tipo; // Normal = 0, Admin = 1
    char senha[15];
    int qtdPlaylists; 
    int playlists[20]; // podem ser playlists onde esse usuario eh dono, contribuinte ou seguidor
};

Usuario* inicializaUsuario(char* nome, int tipo, char* senha, int* playlists){
    Usuario* usuario = (Usuario*) malloc(sizeof(Usuario));

    if (usuario == NULL)
    {
        printf("Erro ao fazer cadastro de usuario!");
        getchar();
        scanf("%*c");
        return usuario;
    }

    usuario->idUsuario = pegaUltimoIdUsuarioCadastrado()+1;
    strcpy(usuario->nome, nome);
    usuario->tipo = tipo;
    strcpy(usuario->senha, senha);
    for (int i = 0; i < 20; i++)
    {
        usuario->playlists[i] = 0;
    }

    return usuario;
}

Usuario* alocarUsuario(int qtd){
    return (Usuario*) malloc(sizeof(Usuario) * qtd);
}

void modificaNomeUsuario(Usuario* usuario, char* nNome){

}

void modificaTipoUsuario(Usuario* usuario, int nTipo){

}

void modificaSenhaUsuario(Usuario* usuario, char* senha){

}

void modificaPlaylistsUsuario(Usuario* usuario, int* playlists){

}

void modificaQtdPlaylistsUsuario(Usuario* usuario, int nQtdPlaylists){
    
}


int pegaIdUsuario(Usuario* usuario){
    return usuario->idUsuario;
}

char* pegaNomeUsuario(Usuario* usuario){
    return usuario->nome;
}

int pegaTipoUsuario(Usuario* usuario){
    return usuario->tipo;
}

char* pegaSenhaUsuario(Usuario* usuario){
    return usuario->senha;
}

int* pegaPlaylistsUsuario(Usuario* usuario){
    return usuario->playlists;
}

int pegaQtdPlaylistsUsuario(Usuario* usuario){
    return usuario->qtdPlaylists;
}


void imprimeUsuario(Usuario* usuario){

}

void destroiUsuario(Usuario* usuario){

}

void salvarUsuarioArquivo(Usuario* usuario){
    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "ab")) == NULL)
    {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
    }

    if ((fwrite(usuario, sizeof (Usuario), 1, arqUsuarios)) == 1) {
        printf("\nUsuario adicionado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }

    fclose(arqUsuarios);
}

int pegaUltimoIdUsuarioCadastrado(){
    Usuario* usuario = alocarUsuario(1);
    int ultimoId;

    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "rb")) == NULL)
    {
        return 0;
    }

    while (fread(usuario, sizeof(Usuario), 1, arqUsuarios) == 1);
    ultimoId = pegaIdUsuario(usuario);

    destroiUsuario(usuario);
    fclose(arqUsuarios);

    return ultimoId;
}