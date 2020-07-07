#include <stdio.h>

#include "aluno.h"
#include "lista.h"

int main() {
    Aluno* patricia = inicializaAluno(123, "Patricia", 10);
    Aluno* alice = inicializaAluno(656, "Alice", 5);
    Aluno* maria = inicializaAluno(21, "Maria", 9);
    Aluno* joao = inicializaAluno(999, "Joao", 8);

    Lista* lista = inicializaLista();

    insereLista(lista, patricia);
    insereLista(lista, alice);
    insereLista(lista, maria);
    insereLista(lista, joao);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    removeAlunoLista(lista, alice);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    insereLista(lista, alice);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    removeAlunoLista(lista, alice);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    removeAlunoLista(lista, patricia);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    destroiLista(lista);

    destroiAluno(patricia);
    destroiAluno(alice);
    destroiAluno(maria);
    destroiAluno(joao);

    return 0;
}