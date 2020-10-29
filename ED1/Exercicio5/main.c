#include <stdio.h>

#include "aluno.h"
#include "lista.h"

int main() {
    Lista* lista = inicializaLista();
    Aluno* aluno1 = inicializaAluno(456, "Victor", 9.22);
    Aluno* aluno2 = inicializaAluno(789, "Pablo", 8.44);
    Aluno* aluno3 = inicializaAluno(123, "Henrique", 8.55);

    lista = insereInicioLista(lista, aluno1);
    lista = insereInicioLista(lista, aluno2);
    lista = insereInicioLista(lista, aluno3);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    lista = removeAlunoLista(lista, 456);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    lista = removeAlunoLista(lista, 123);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    lista = removeAlunoLista(lista, 789);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    lista = insereInicioLista(lista, aluno3);
    lista = insereInicioLista(lista, aluno2);
    lista = insereInicioLista(lista, aluno1);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    lista = removeAlunoLista(lista, 789);
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    destroiLista(lista);
    destroiAluno(aluno1);
    destroiAluno(aluno2);
    destroiAluno(aluno3);

    return 0;
}