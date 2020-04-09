#include <stdio.h>

#include "aluno.h"
#include "lista.h"

int main() {
    Lista* lista = inicializaLista();
    Aluno* alunoRemovido;

    insereInicioLista(lista, inicializaAluno(456, "Victor", 9.22));
    insereFimLista(lista, inicializaAluno(789, "Pablo", 8.44));
    insereInicioLista(lista, inicializaAluno(123, "Henrique", 8.55));
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    alunoRemovido = removeAlunoLista(lista, 123);
    imprimeLista(lista);
    printf("Aluno Removido: ");
    imprimeAluno(alunoRemovido);
    printf("------------------------------------------------\n");
    destroiAluno(alunoRemovido);

    alunoRemovido = removeAlunoLista(lista, 789);
    imprimeLista(lista);
    printf("Aluno Removido: ");
    imprimeAluno(alunoRemovido);
    printf("------------------------------------------------\n");
    destroiAluno(alunoRemovido);

    alunoRemovido = removeAlunoLista(lista, 456);
    imprimeLista(lista);
    printf("Aluno Removido: ");
    imprimeAluno(alunoRemovido);
    printf("------------------------------------------------\n");
    destroiAluno(alunoRemovido);

    insereInicioLista(lista, inicializaAluno(456, "Victor", 9.22));
    insereInicioLista(lista, inicializaAluno(123, "Henrique", 8.55));
    insereFimLista(lista, inicializaAluno(789, "Pablo", 8.44));
    imprimeLista(lista);
    printf("------------------------------------------------\n");

    alunoRemovido = removeAlunoLista(lista, 456);
    imprimeLista(lista);
    printf("Aluno Removido: ");
    imprimeAluno(alunoRemovido);
    printf("------------------------------------------------\n");
    destroiAluno(alunoRemovido);

    destroiLista(lista);

    return 0;
}