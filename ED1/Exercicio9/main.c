#include <stdlib.h>

#include "aluno.h"
#include "arvore.h"
#include "stdio.h"

int main(int argc, char *argv[]) {
    Aluno *hen, *gab, *pab, *vic, *hel, *mur;

    hen = inicializaAluno(1, "Henrique\0", 9);
    gab = inicializaAluno(2, "Gabrielly\0", 8);
    pab = inicializaAluno(3, "Pablo\0", 8);
    vic = inicializaAluno(4, "Victor\0", 7);
    hel = inicializaAluno(5, "Helena\0", 4);
    mur = inicializaAluno(6, "Murilo\0", 1);

    Arv *arv = arvCria(hen,
                       arvCria(gab,
                               arvCriaVazia(),
                               arvCria(vic,
                                       arvCriaVazia(),
                                       arvCriaVazia())),
                       arvCria(pab,
                               arvCria(hel,
                                       arvCriaVazia(),
                                       arvCriaVazia()),
                               arvCria(mur,
                                       arvCria(hen,
                                               arvCriaVazia(),
                                               arvCriaVazia()),
                                       arvCriaVazia())));

    arvImprime(arv);

    printf("\nAluno chamado Henrique pertence a arvore?: %d",
           arvPertence(arv, "Henrique"));
    printf("\nAluna chamada Flavia pertence a arvore?: %d",
           arvPertence(arv, "Flavia"));
    printf("\nNumero de folhas da arvore: %d",
           folhas(arv));
    printf("\nAltura da arvore: %d",
           altura(arv));
    printf("\nPai de Helena eh: %s",
           retornaNome(info(arvPai(arv, "Helena"))));
    printf("\nNumero de ocorrencias de Henrique: %d",
           ocorrencias(arv, "Henrique"));
    printf("\n");

    arvLibera(arv);

    destroiAluno(hen);
    destroiAluno(gab);
    destroiAluno(pab);
    destroiAluno(vic);
    destroiAluno(hel);
    destroiAluno(mur);

    return 0;
}