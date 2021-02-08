#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main() {
    float num1, num2, num3, result;
    char c, sinal;

    scanf("%f %f %c", &num1, &num2, &sinal);
    switch (sinal) {
        case '+':
            result = Soma(num1, num2);
            break;

        case '-':
            result = Subtracao(num1, num2);
            break;

        case '*':
            result = Multiplicacao(num1, num2);
            break;

        case '/':
            result = Divisao(num1, num2);
            break;
    }

    while (scanf("%c", &c) == 1) {
        if (c >= '0' && c <= '9') {
            num3 = c - 48;
        } else {
            switch (c) {
                case '+':
                    result = Soma(result, num3);
                    break;

                case '-':
                    result = Subtracao(result, num3);
                    break;

                case '*':
                    result = Multiplicacao(result, num3);
                    break;

                case '/':
                    result = Divisao(result, num3);
                    break;
            }
        }
    }

    printf("%.2f", result);
    return 0;
}

float Soma(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

