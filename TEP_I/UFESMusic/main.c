#include <stdio.h>
#include "playlist.h"
#include "album.h"
#include "usuario.h"
#include "midia.h"
#include "impressoes.h"
#include <stdlib.h>
#include <string.h>

void fazerLogin();
void cadastrarUsuario(int verificador);
void menuAdmin();
void menuUsuario();
void gerenciarMidia();
void gerenciarPlaylst();
void gerenciarAlbuns();
void gerenciarUsuarios();
void adicionarMidia();
void editarMidia(Midia* midia, int opcao, int indice);
void menuListarTodasMidias();
void excluirMidia();
Album* adicionarAlbum();


int main(int argc, char** argv) {
    int opcao;

    do
    {
        //system("clear");
        imprimeMenuPrincipal();
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1:
            fazerLogin();
            break;
        
        case 2:
            cadastrarUsuario(0);
            break;
        }
        
    } while (opcao != 3);
    

    return 0;
}

void fazerLogin(){
    int op;
    printf("Digite 0 para menu normal ou 1 para menu admin: ");
    scanf("%d", &op);

    if (op)
    {
        menuAdmin();
        return;
    }
    menuUsuario();
    
}

void cadastrarUsuario(int verificador){
    char nome[50], senha[15];
    int tipo;
    Usuario* usuario;
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua senha: ");
    scanf("%s", senha);
    if (verificador)
    {
        printf("Digite o tipo de usuario: ");
        scanf("%d", &tipo);
    }else
    {
        tipo = 0;
    }

    usuario = inicializaUsuario(nome, tipo, senha);

    FILE* arqUsuarios;

    if ((arqUsuarios = fopen("usuarios.dat", "ab")) == NULL)
    {
        printf("\nErro ao abrir arquivo de usuarios!");
        getchar();
        scanf("%*c");
        return;
    }

    if (fwrite(usuario, 73, 1, arqUsuarios) == 1){
        printf("\nUsuario cadastrado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }
    
    fclose(arqUsuarios);
}

void menuAdmin(){
    int opcao;

    do
    {
        //system("clear")
        imprimeMenuOpcoesAdmin();
        scanf("%d", &opcao);
        switch (opcao)
        {
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

void gerenciarMidia(){
    int opcao;

    do
    {
        //system("clear")
        imprimeMenuGerenciarMidia();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            adicionarMidia();
            break;

        case 2:
            menuListarTodasMidias();
            break;

        case 3:
            imprimeMenuBuscarMidias();
            break;

        }
    } while (opcao != 4);
}

void adicionarMidia(){
    char nome[50], compositores[3][50], artistas[3][50], genero[15], gravadora[15], duracao[10];
    Album* album;
    int tipo, qtdCompositores, qtdArtistas, i, j, indiceAlbum;
    Midia* midia;

    getchar();
    printf("\nDigite o nome da midia: ");
    scanf("%[^\n]s", nome);
    printf("\nDigite o tipo de midia (0 musica, 1 video): ");
    scanf("%d", &tipo);
    printf("\nDigite quantos compositores a midia possui: ");
    scanf("%d%*c", &qtdCompositores);
    for (i = 0; i < qtdCompositores; i++)
    {
        printf("\nDigite o compositor %d: ", i+1);
        scanf("%[^\n]s%*c", compositores[i]);
    }
    for ( i ; i < qtdCompositores; i++)
    {
        compositores[i][0] = '\0';
    }
    printf("\nDigite quantos artistas a midia possui: ");
    scanf("%d%*c", &qtdArtistas);
    for (i = 0; i < qtdArtistas; i++)
    {
        printf("\nDigite o artista %d: ", i+1);
        scanf("%[^\n]s%*c", artistas[i]);
    }
    for ( i ; i < qtdArtistas; i++)
    {
        artistas[i][0] = '\0';
    }
    printf("\nDigite o genero da midia: ");
    scanf("%s%*c", genero);
    printf("\nDigite a gravadora da midia: ");
    scanf("%[^\n]s", gravadora);
    printf("\nDigite a duracao da midia (MM:SS): ");
    scanf("%s", duracao);
    /*printf("\nEscolha o album a qual a midia pertence: ");
    listarTodosAlbum();
    printf("\nDigite o indice do album desejado, ou 0 para adicionar um novo album: ");
    scanf("%d", &indiceAlbum);
    if (!indiceAlbum)
    {
        album = adicionarAlbum();
    }else
    {
        album = buscarAlbum(indiceAlbum);
    }*/
    
    midia = inicializaMidia(nome, tipo, compositores, artistas, genero, gravadora, duracao, album);
    
    FILE* arqMidias;

    if ((arqMidias = fopen("midias.dat", "ab")) == NULL)
    {
        printf("\nErro ao abrir arquivo de midias!");
        getchar();
        scanf("%*c");
    }

    /*if (fwrite(midia, sizeof(Midia), 1, arqMidias) == 1)
    {
        printf("\nNova midia adicionada com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }*/
    
    fclose(arqMidias);
    
}

void menuListarTodasMidias(){
    Midia* midia;
    int indice, opcaoMenu;

    printf("\nListando todas as midias...");
    listarTodasMidias();
    printf("\nDigite o indice da midia ou 0 para voltar: ");
    scanf("%d", &indice);
    midia = buscarMidia(indice);

    if (indice)
    {
        do
        {
            imprimeMenuOpcoesMidiaAdmin();
            scanf("%d", &opcaoMenu);
            editarMidia(midia, opcaoMenu, indice);
        } while (opcaoMenu != 9);
    }
}

void editarMidia(Midia* midia, int opcao, int indice){
    char nome[50], compositores[3][50], artistas[3][50], genero[15], gravadora[15], duracao[10];
    int tipo;

    switch (opcao)
    {
    case 1:
        printf("\nDigite o novo nome para a midia: ");
        scanf("%[^\n]s", nome);
        modificaNomeMidia(midia, nome);
    break;

    case 2:
        printf("\nDigite o novo tipo para a midia (0 musica, 1 video): ");
        scanf("%d", &tipo);
        modificaTipoMidia(midia, tipo);
    break;

    case 3:
        /* code */
    break;

    case 4:
        /* code */
    break;

    case 5:
        /* code */
    break;

    case 6:
        /* code */
    break;

    case 7:
        /* code */
    break;

    case 8:
        /* code */
    break;
    
    }
}

void excluirMidia(){
    
}

void gerenciarPlaylst(){
    
}

void gerenciarAlbuns(){
    
}

void gerenciarUsuarios(){
    
}

Album* adicionarAlbum(){
    char nome[50], particiapantes[3][50], dataLancamento[11];
    int qtdParticipantes, i;
    Album* album;
    getchar();
    printf("\nDigite o nome do album: ");
    scanf("%[^\n]s", nome);
    printf("\nDigite a quantidade de participantes do album: ");
    scanf("%d%*c", &qtdParticipantes);
    for (i = 0; i < qtdParticipantes; i++)
    {
        printf("\nDigite o participante %d: ", i);
        scanf("%[^\n]s%*c", particiapantes[i]);
    }
    for ( i ; i < qtdParticipantes; i++)
    {
        particiapantes[i][0] = '\0';
    }
    printf("\nDigite a data de lancamento do album (DD:MM:AAAA): ");
    scanf("%s", dataLancamento);

    album = inicializaAlbum(nome, particiapantes, dataLancamento);

    FILE* arqAlbuns;

    if ((arqAlbuns = fopen("albuns.dat", "ab")) == NULL)
    {
        printf("\nErro ao abrir arquivo de albuns!");
        getchar();
        scanf("%*c");
    }

    /*if ((fwrite(album, sizeof(Album), 1, arqAlbuns)) == 1){
        printf("\nAlbum adicionado com sucesso!");
        printf("\nPressione ENTER para continuar...");
        getchar();
        scanf("%*c");
    }*/

    fclose(arqAlbuns);

    return album;    
}

void menuUsuario(){

}
