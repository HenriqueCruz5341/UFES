#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
} Aluno;

char* le_nome() {
    char nome[121];
    scanf("%120[^\n]", nome);

    return strdup(nome);
}

void imprime_turma(int n, Aluno** turma) {
    printf("===| Imprimindo lista de alunos |===\n");
    for (int i = 0; i < n; i++) {
        printf("==| Aluno %d |==\n", i + 1);
        printf("Nome: %s\n", turma[i]->nome);
        printf("Matricula: %d\n", turma[i]->matricula);
        printf("P1, P2 e P3: %.2f %.2f %.2f\n", turma[i]->p1, turma[i]->p2, turma[i]->p3);
    }
}

void imprime_aprovados(int n, Aluno** turma) {
    printf("===| Imprimindo lista de aprovados |===\n");
    for (int i = 0; i < n; i++) {
        if ((turma[i]->p1 + turma[i]->p2 + turma[i]->p3) / 3 >= 5) {
            printf("==| Aluno %d |==\n", i + 1);
            printf("Nome: %s\n", turma[i]->nome);
            printf("Matricula: %d\n", turma[i]->matricula);
            printf("P1, P2 e P3: %.2f %.2f %.2f\n", turma[i]->p1, turma[i]->p2, turma[i]->p3);
        }
    }
}

float media_turma(int n, Aluno** turma) {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        cont += (turma[i]->p1 + turma[i]->p2 + turma[i]->p3) / 3;
    }

    return cont / n;
}

int main() {
    int qtd;

    printf("Digite quantos alunos tem na turma: ");
    scanf("%d", &qtd);

    Aluno** turma = (Aluno**)malloc(qtd * sizeof(Aluno*));

    for (int i = 0; i < qtd; i++) {
        Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
        turma[i] = aluno;
        printf("===| Preenchendo aluno %d |===\n", i + 1);
        scanf("%*c");
        printf("Digite o nome: ");
        turma[i]->nome = le_nome();
        printf("Digite a matrícula: ");
        scanf("%d", &(turma[i]->matricula));
        printf("Digite as notas da p1, p2 e p3 (separadas por espaço): ");
        scanf("%f %f %f", &(turma[i]->p1), &(turma[i]->p2), &(turma[i]->p3));
    }

    imprime_aprovados(qtd, turma);

    media_turma(qtd, turma);

    printf("\nA media da turma eh: %.2f", media_turma(qtd, turma));

    for (int i = 0; i < qtd; i++) {
        free(turma[i]->nome);
        free(turma[i]);
    }

    free(turma);

    return 0;
}
