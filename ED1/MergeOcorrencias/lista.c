#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char* nome;
    int matricula;
};

char* RetornaNome(TAluno* aluno) {
    return aluno->nome;
}

int RetornaMatricula(TAluno* aluno) {
    return aluno->matricula;
}

typedef struct celula Celula;

struct celula {
    TAluno* aluno;
    Celula* prox;
};

struct lista {
    Celula* ini;
    Celula* fim;
};

TLista* CriaLista() {
    TLista* lista = (TLista*)malloc(sizeof(TLista));
    lista->ini = NULL;
    lista->fim = NULL;

    return lista;
}

TAluno* InicializaAluno(char* nome, int matricula) {
    TAluno* aluno = (TAluno*)malloc(sizeof(TAluno));
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;

    return aluno;
}

void InsereAluno(TLista* lista, TAluno* aluno) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->aluno = aluno;

    if (lista->ini == NULL) {
        lista->ini = nova;
        lista->fim = nova;
        nova->prox = NULL;
    } else {
        nova->prox = lista->ini;
        lista->ini = nova;
    }
}

void InsereAlunoFim(TLista* lista, TAluno* aluno) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->aluno = aluno;
    nova->prox = NULL;

    if (lista->ini == NULL) {
        lista->ini = nova;
        lista->fim = nova;
    } else {
        lista->fim->prox = nova;
        lista->fim = nova;
    }
}

TAluno* Retira(TLista* lista, int mat) {
    Celula* cel = lista->ini;
    Celula* ant;
    TAluno* aluno;

    while (cel != NULL && RetornaMatricula(cel->aluno) != mat) {
        ant = cel;
        cel = cel->prox;
    }
    if (cel == NULL) return NULL;

    if (cel == lista->ini && cel == lista->fim) {
        lista->ini = NULL;
        lista->fim = NULL;
    } else if (cel == lista->ini) {
        lista->ini = cel->prox;
    } else if (cel == lista->fim) {
        lista->fim = ant;
        ant->prox = NULL;
    } else {
        ant->prox = cel->prox;
    }
    aluno = cel->aluno;
    free(cel);

    return aluno;
}

void RetiraRepetidos(TLista* lista) {
    Celula* cel1;
    Celula* prox;
    Celula* cel2;
    Celula* ant;

    //Ideia q não deu certo pq quando eu liberava a lista, liberava os alunos tb... :(
    // TLista* novaLista = CriaLista();
    // int achou = 0;

    // for (cel1 = lista->ini; cel1 != NULL; cel1 = cel1->prox) {
    //     achou = 0;
    //     for (cel2 = novaLista->ini; cel2 != NULL; cel2 = cel2->prox) {
    //         if (RetornaMatricula(cel1->aluno) == RetornaMatricula(cel2->aluno)) {
    //             achou = 1;
    //             break;
    //         }
    //     }
    //     if (!achou)
    //         InsereAlunoFim(novaLista, cel1->aluno);
    // }

    // LiberaLista(lista);
    // lista = novaLista;

    for (cel1 = lista->ini; cel1 != NULL; cel1 = cel1->prox) {
        cel2 = cel1;
        while (cel2 != NULL) {
            ant = cel2;
            cel2 = cel2->prox;
            if (cel2 == NULL) break;
            if (cel1->aluno == cel2->aluno) {
                prox = cel2->prox;
                if (cel2 == lista->fim) {
                    lista->fim = ant;
                    ant->prox = NULL;
                } else {
                    ant->prox = cel2->prox;
                }
                free(cel2);
                cel2 = prox;
            }
        }
    }
}

TLista* Merge(TLista* turma1, TLista* turma2) {
    Celula* cel1;
    Celula* cel2;
    Celula* prox1;
    Celula* prox2;
    TLista* novaLista = CriaLista();

    cel1 = turma1->ini;
    cel2 = turma2->ini;

    while (cel1 != NULL && cel2 != NULL) {
        prox1 = cel1->prox;
        prox2 = cel2->prox;
        InsereAlunoFim(novaLista, cel1->aluno);
        Retira(turma1, RetornaMatricula(cel1->aluno));
        InsereAlunoFim(novaLista, cel2->aluno);
        Retira(turma2, RetornaMatricula(cel2->aluno));
        cel1 = prox1;
        cel2 = prox2;
    }

    if (cel1 != NULL) {
        while (cel1 != NULL) {
            prox1 = cel1->prox;
            InsereAlunoFim(novaLista, cel1->aluno);
            Retira(turma1, RetornaMatricula(cel1->aluno));
            cel1 = prox1;
        }
    } else if (cel2 != NULL) {
        while (cel2 != NULL) {
            prox2 = cel2->prox;
            InsereAlunoFim(novaLista, cel2->aluno);
            Retira(turma2, RetornaMatricula(cel2->aluno));
            cel2 = prox2;
        }
    }

    return novaLista;
}

void LiberaAluno(TAluno* aluno) {
    if (aluno != NULL) {
        if (RetornaNome(aluno) != NULL) free(aluno->nome);
        free(aluno);
    }
}

void Imprime(TLista* lista) {
    for (Celula* cel = lista->ini; cel != NULL; cel = cel->prox) {
        printf("Aluno: %s | %d\n", RetornaNome(cel->aluno), RetornaMatricula(cel->aluno));
    }
    printf("\n");
}

void LiberaLista(TLista* lista) {
    Celula* prox;
    Celula* cel = lista->ini;

    while (cel != NULL) {
        prox = cel->prox;
        LiberaAluno(cel->aluno);
        free(cel);
        cel = prox;
    }

    free(lista);
}
