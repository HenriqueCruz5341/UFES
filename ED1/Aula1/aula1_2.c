#include<stdio.h>
#include<stdlib.h>

// 2.1)
/*
void  calc_esfera (float r, float* area, float* volume){
    *area = 4 * 3.1415 * r * r;
    *volume = (4 * r * r * r * 3.1415)/3;
}

int main(){
    float raio, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);

    printf("A area da superficie da esfera com o raio digitado eh: %f", area);
    printf("\nO volume da esfera com o raio digitado eh: %f\n", volume);

    return 0;
}
*/

// 2.2)
/*
void fatorial (int n, int* f){
    *f = n;

    for(n = n-1; n > 0; n--){
        *f = (*f) * n;
    }
}

int main(){
    int n, fat;

    printf("Digite o numero que se deseja calcular o fatorial: ");
    scanf("%d", &n);

    fatorial(n, &fat);

    printf("O fatorial do numero digitado eh: %d\n", fat);

    return 0;
}
*/

//2.3)
/*
int negativos (int n, float*vet){
    int cont = 0;

    for(n-1; n >= 0; n--){
        if(vet[n] < 0) cont++;
    }

    return cont;
}

int main(){
    int n, i = 0;

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &n);

    float *vet;
    vet = (float*) malloc(n*sizeof(float));

    for(i = 0; i < n; i++){
        printf("\nDigite o valor de vet[%d]: ", i);
        scanf("%f", &vet[i]);
    }

    printf("Seu vetor possui %d numeros negativos!\n", negativos(n, vet));

    free(vet);

    return 0;
}
*/

//2.4)

void inverte (int n, int* vet){
    int aux, i;

    for(i = 0; i < n/2; i++){
        aux = vet[n-i-1];
        vet[n-i-1] = vet[i];
        vet[i] = aux;
    }
}

int main(){
    int n, i = 0;

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &n);

    int *vet;
    vet = (int*) malloc(n*sizeof(int));

    for(i = 0; i < n; i++){
        printf("\nDigite o valor de vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("Seu vetor normal: \n");
    for(i = 0; i < n; i++){
        if(i != 0) printf("| ");
        printf("%d", vet[i]);
    }

    inverte(n, vet);

    printf("\nSeu vetor invertido: \n");
    for(i = 0; i < n; i++){
        if(i != 0) printf("| ");
        printf("%d", vet[i]);
    }
    printf("\n");
    

    free(vet);

    return 0;
}
