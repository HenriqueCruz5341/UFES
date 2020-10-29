#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
int raizes(float a, float b, float c, float* x1, float* x2) {
    float delta = b * b - (4 * a * c);

    if (delta < 0) return 0;

    *x1 = (-b + (sqrtf(delta))) / (2 * a);
    *x2 = (-b - (sqrtf(delta))) / (2 * a);

    return 1;
}

int main() {
    int a, b, c;
    float x1, x2;

    printf("Digite os valores de (a b c) separados por espaco: ");
    scanf("%d %d %d", &a, &b, &c);

    if (raizes(a, b, c, &x1, &x2))
        printf("x1: %.2f | x2: %.2f\n", x1, x2);
    else
        printf("A equecao nao possui raiz real.\n");

    return 0;
}
*/

//2.3)
/*
int pares(int n, int *vet) {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        if (!(vet[i] % 2)) cont++;
    }

    return cont;
}

int main() {
    int n, i = 0;

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &n);

    int *vet;
    vet = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("\nDigite o valor de vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("Seu vetor possui %d numeros pares!\n", pares(n, vet));

    free(vet);

    return 0;
}
*/

//2.4)

void inverte(int n, int* vet) {
    int aux, i;

    for (i = 0; i < n / 2; i++) {
        aux = vet[n - i - 1];
        vet[n - i - 1] = vet[i];
        vet[i] = aux;
    }
}

int main() {
    int n, i = 0;

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &n);

    int* vet;
    vet = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("\nDigite o valor de vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("Seu vetor normal: \n");
    for (i = 0; i < n; i++) {
        if (i != 0) printf("| ");
        printf("%d", vet[i]);
    }

    inverte(n, vet);

    printf("\nSeu vetor invertido: \n");
    for (i = 0; i < n; i++) {
        if (i != 0) printf("| ");
        printf("%d", vet[i]);
    }
    printf("\n");

    free(vet);

    return 0;
}

//2.5)
/*
double avalia(double* poli, int grau, double x) {
    double result = 0;
    for (int i = grau; i >= 0; i--)
        result += poli[i] * pow(x, i);

    return result;
}

int main() {
    int grau;
    double x;

    printf("Digite o grau do seu polinomio: ");
    scanf("%d", &grau);

    double* poli = (double*)malloc(sizeof(double) * (grau + 1));

    printf("\nDigite seu polinomio: ");
    for (int i = 0; i <= grau; i++) scanf("%lf", poli + i);

    printf("\nDigite o valor de X: ");
    scanf("%lf", &x);

    double result = avalia(poli, grau, x);

    printf("Seu polinomio avaliado: %.2lf\n", result);

    free(poli);
    return 0;
}
*/