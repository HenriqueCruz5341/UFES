#include <stdlib.h>

#include "abb.h"
#include "aluno.h"
#include "stdio.h"

int main(int argc, char *argv[]) {
    Aluno *hen, *gab, *pab, *vic, *hel, *mur;

    hen = inicializaAluno(1, "Henrique\0", 9);
    gab = inicializaAluno(2, "Gabrielly\0", 8);
    pab = inicializaAluno(3, "Pablo\0", 8);
    vic = inicializaAluno(4, "Victor\0", 7);
    hel = inicializaAluno(5, "Helena\0", 4);
    mur = inicializaAluno(6, "Murilo\0", 1);

    Arv *abb = abbCria();

    abb = abbInsere(abb, vic);
    abb = abbInsere(abb, hen);
    abb = abbInsere(abb, gab);
    abb = abbInsere(abb, pab);
    abb = abbInsere(abb, hel);
    abb = abbInsere(abb, mur);

    abbImprime(abb);

    abb = abbRetira(abb, retornaMatricula(vic));

    printf("\nArvore sem Victor:\n");
    abbImprime(abb);

    abb = abbRetira(abb, retornaMatricula(mur));

    printf("\nArvore sem Murilo:\n");
    abbImprime(abb);

    abb = abbRetira(abb, retornaMatricula(pab));

    printf("\nArvore sem Pablo:\n");
    abbImprime(abb);

    abb = abbInsere(abb, vic);

    printf("\nInserindo Victor:\n");
    abbImprime(abb);

    abbLibera(abb);

    destroiAluno(hen);
    destroiAluno(gab);
    destroiAluno(pab);
    destroiAluno(vic);
    destroiAluno(hel);
    destroiAluno(mur);

    return 0;
}