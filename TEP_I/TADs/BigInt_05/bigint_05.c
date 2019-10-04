#include<stdio.h>

typedef struct {
    int intGrande[100];
} tIntGrande;

void LeNumero(tIntGrande *n) {
    int i = 99, qtd, aux, k, vezes, j;
    char num;

    while (scanf("%c", &num) == 1) {
        if (num == ' ') {
            break;
        }
        n->intGrande[i] = num - 48;
        i--;
    }

    qtd = i + 1;
    vezes = (100 - qtd)/2;
    j = 99;
    for (k = 0; k < vezes; k++) {
        aux = n->intGrande[j];
        n->intGrande[j] = n->intGrande[qtd];
        n->intGrande[qtd] = aux;
        j--;
        qtd++;
    }

    while (i >= 0) {
        n->intGrande[i] = 0;
        i--;
    }
}

void ImprimirIntGrande(tIntGrande n) {
    int i = 0;

    while (n.intGrande[i] == 0) {
        i++;
    }

    if (i != 100) {
        for (i; i < 100; i++) {
            printf("%d", n.intGrande[i]);
        }
    }else{
        printf("0");
    }
}

tIntGrande MultiplicacaoIntGrande(tIntGrande num1, int num2) {
    tIntGrande mult;
    int i = 0, j = 0, aux;


    for (i = 99; i >= 0; i--) {
        mult.intGrande[i] = num1.intGrande[i] * num2;
    }

    for (i = 99; i >= 0; i--) {
        if (mult.intGrande[i] > 9) {
            aux = mult.intGrande[i] / 10;
            mult.intGrande[i - 1] += aux;
            mult.intGrande[i] %= 10;
        }
    }

    return mult;
}

int main() {
    tIntGrande num1, mult;
    int num2;

    LeNumero(&num1);
    scanf("%d", &num2);

    mult = MultiplicacaoIntGrande(num1, num2);

    ImprimirIntGrande(mult);

    return 0;
}
