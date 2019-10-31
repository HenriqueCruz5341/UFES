typedef struct midia
{
    char nome[50];
    int tipo;
    char compositores[3][50];
    char artistas[3][50];
    char genero[50];
    char gravadora[50];
    char duracao[5];
    char album[50];
}Midia;

typedef struct album
{
    char participantes[3][50];
    char dataLancamento[10];
    Midia* midia[50];
}Album;

typedef struct playlist
{
    int privacidade;
    char contribuintes[3][50];
    char dataLancamento[10];
    Midia* midia[50];
}Playlist;
