#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int vet[], int tamVet);
int ProcuraNumeroEmB(int vet[], int tamVet, int num);

int main(int argc, char** argv) {
    int tam1, tam2, i, cont = 0;
    
    scanf("%d", &tam1);
    int vetor1[tam1];
    PreencheVetor(vetor1, tam1);
    
    scanf("%d", &tam2);
    int vetor2[tam2];
    PreencheVetor(vetor2, tam2);
    
    for(i = 0; i < tam1; i++){
        if(ProcuraNumeroEmB(vetor2, tam2, vetor1[i])){
            cont++;
        }
    }
    
    if(cont == tam1){
        printf("TODOS");
    }else if(cont){
        printf("PARCIAL");
    }else{
        printf("NENHUM");
    }
    
    return 0;
}

void PreencheVetor(int vet[], int tamVet){
    int i;
    
    for(i = 0; i < tamVet; i++){
        scanf("%d", &vet[i]);
    }
}

int ProcuraNumeroEmB(int vet[], int tamVet, int num){
    int i;
    
    for(i = 0; i < tamVet; i++){
        if(num == vet[i]){
            return 1;
        }
    }
    
    return 0;
}
