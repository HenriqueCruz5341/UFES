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
};

Usuario* inicializaUsuario(char* nome, int tipo, char* senha){
    Usuario* usuario = (Usuario*) malloc(sizeof(Usuario));

    if (usuario == NULL)
    {
        printf("Erro ao fazer cadastro de usuario!");
        getchar();
        scanf("%*c");
        return usuario;
    }

    strcpy(usuario->nome, nome);
    usuario->tipo = tipo;
    strcpy(usuario->senha, senha);

    return usuario;
}

void modificaNomeUsuario(Usuario* usuario, char* nNome){

}

void modificaTipoUsuario(Usuario* usuario, int nTipo){

}

void modificaSenhaUsuario(Usuario* usuario, char* senha){

}

char* pegaNomeUsuario(Usuario* usuario){

}

int pegaTipoUsuario(Usuario* usuario){

}

char* pegaSenhaUsuario(Usuario* usuario){

}

void imprimeUsuario(Usuario* usuario){

}

void destroiUsuario(Usuario* usuario){

}