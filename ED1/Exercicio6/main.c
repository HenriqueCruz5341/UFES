#include <stdio.h>

#include "aluno.h"
#include "lista.h"
#include "professor.h"

int main() {
    Aluno* aluno1 = inicializaAluno(123, "Henrique", 8.88);
    Aluno* aluno2 = inicializaAluno(456, "Pablo", 7.58);
    Aluno* aluno3 = inicializaAluno(789, "Victor", 9.01);

    Professor* professor1 = inicializaProfessor(159, "Gabrielly", 7854.33);
    Professor* professor2 = inicializaProfessor(357, "Helena", 1234.55);

    Lista* lista = inicializaLista();

    insereItem(lista, aluno1, 1);
    insereItem(lista, professor1, 0);
    insereItem(lista, aluno2, 1);
    insereItem(lista, professor2, 0);
    insereItem(lista, aluno3, 1);

    imprimeLista(lista);

    float churrasco = valorChurrasco(lista);
    printf("\nNo momento, temos R$ %.2f para o churrasco!\n", churrasco);

    destroiAluno(aluno1);
    destroiAluno(aluno2);
    destroiAluno(aluno3);
    destroiProfessor(professor1);
    destroiProfessor(professor2);
    destroiLista(lista);

    return 0;
}