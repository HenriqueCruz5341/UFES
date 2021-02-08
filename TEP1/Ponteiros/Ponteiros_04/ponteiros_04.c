#include<stdio.h>

void le_dados(int *num1) {
    scanf("%d", num1);
}

int maior(int num1, int num2, int *dif) {
    if (num1 > num2) {
        *dif = num1 - num2;
        return num1;
    } else {
        *dif = num2 - num1;
        return num2;
    }
}

float media(int num1, int num2, int *soma) {
    float m;

    *soma = num1 + num2;
    m = *soma / 2.0;
    
    return m;
}

