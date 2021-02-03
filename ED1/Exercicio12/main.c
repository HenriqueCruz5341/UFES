#include <stdio.h>

#include "listaalunos.h"

int main() {
    ListaGen* lista = criaLista();

    Aluno* aluno1 = inicializaAluno(123, "Henrique", 10.0);
    Aluno* aluno2 = inicializaAluno(456, "Pablo", 8.0);
    Aluno* aluno3 = inicializaAluno(789, "Victor", 9.5);
    Aluno* aluno4 = inicializaAluno(147, "André", 4.0);
    Aluno* aluno5 = inicializaAluno(258, "Gabrielly", 1.0);
    Aluno* aluno6 = inicializaAluno(369, "Murilo", 9.0);
    Aluno* aluno7 = inicializaAluno(159, "Helena", 10.0);
    Aluno* aluno8 = inicializaAluno(357, "Flavia", 7.0);

    lista = insereLista(lista, aluno1);
    lista = insereLista(lista, aluno2);
    lista = insereLista(lista, aluno3);
    lista = insereLista(lista, aluno4);
    lista = insereLista(lista, aluno5);
    lista = insereLista(lista, aluno6);
    lista = insereLista(lista, aluno7);

    imprimeListaAlunos(lista);

    lista = retiraAluno(lista, 456);

    printf("\n---------------------------------\n\n");
    imprimeListaAlunos(lista);

    int i = pertenceAluno(lista, 1);
    if (i == 0) {
        printf("\nAluno esta na lista!\n");
    } else {
        printf("Aluno NAO esta na lista!\n");
    }

    printf("\nA media da turma é: %.2f\n", mediaTurma(lista));

    liberaLista(lista);

    destroiAluno(aluno1);
    destroiAluno(aluno2);
    destroiAluno(aluno3);
    destroiAluno(aluno4);
    destroiAluno(aluno5);
    destroiAluno(aluno6);
    destroiAluno(aluno7);
    destroiAluno(aluno8);

    return 0;
}