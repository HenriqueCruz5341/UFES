#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int curso;
    int matricula;
    float coeficiente;
}Aluno;

void LeAluno(FILE* arquivo, Aluno aluno[], int* qtd){
    
    while(fscanf(arquivo, "%d %d %f", &aluno[*qtd].curso, &aluno[*qtd].matricula, &aluno[*qtd].coeficiente) == 3){
        (*qtd)++;
    }
}

void OrdenarCurso(int qtd, Aluno aluno[qtd]){
    int i = 0, j = 0;
    Aluno aux;
    
    for(i = 0; i < qtd; i++){
        for(j = i; j < qtd; j++){
            if(aluno[j].curso < aluno[i].curso){
                aux = aluno[j];
                aluno[j] = aluno[i];
                aluno[i] = aux;
            }
        }
    }
}

void OrdenarMatricula(int qtd, Aluno aluno[qtd]){
    int i = 0, j = 0;
    Aluno aux;
    
    for(i = 0; i < qtd; i++){
        for(j = i; j < qtd; j++){
            if(aluno[j].matricula < aluno[i].matricula && aluno[j].curso == aluno[i].curso){
                aux = aluno[j];
                aluno[j] = aluno[i];
                aluno[i] = aux;
            }
        }
    }
}

void GerarArquivo(int qtd, Aluno aluno[qtd]){
    int i = 0;
    FILE* saida = fopen("/home/2019107869/Exercicios/TEP_I/saida.txt", "w");
    
    for(i = 0; i < qtd; i++){
        fprintf(saida, "%03d %d %.1f\n", aluno[i].curso, aluno[i].matricula, aluno[i].coeficiente);
    }
}

int main(int argc, char** argv){
    FILE* arquivo = fopen("/home/2019107869/Exercicios/TEP_I/Struct_01/crs.txt", "r");
    Aluno alunos[3000];
    int qtdAlunos;
    
    LeAluno(arquivo, alunos, &qtdAlunos);
    OrdenarCurso(qtdAlunos, alunos);
    OrdenarMatricula(qtdAlunos, alunos);
    GerarArquivo(qtdAlunos, alunos);
    
    fclose(arquivo);
    return 0;
}

