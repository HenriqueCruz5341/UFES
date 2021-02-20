#include <stdio.h>
#include <string.h>

#include "Pilha.h"
#include "PilhaOperador.h"
#include "PilhaOperando.h"

double calculadora(double num1, double num2, char op);

int ehOperador(char carac);

int ehOperando(char carac);

int main() {
    double num1, num2, result;
    char str[100], op;
    PilhaOperando* pilhaOperando = inicializaPilhaOperando();
    PilhaOperador* pilhaOperador = inicializaPilhaOperador();
    scanf("%[^\n]", str);

    for (int i = 0; i < strlen(str); i++) {
        result = 0;
        if (ehOperador(str[i]))
            pushPilhaOperador(pilhaOperador, str[i]);
        else if (ehOperando(str[i]))
            pushPilhaOperando(pilhaOperando, str[i] - 48);
        else if (str[i] == ')') {
            num1 = popPilhaOperando(pilhaOperando);
            num2 = popPilhaOperando(pilhaOperando);
            op = popPilhaOperador(pilhaOperador);
            result = calculadora(num1, num2, op);
            pushPilhaOperando(pilhaOperando, result);
        }
    }
    result = popPilhaOperando(pilhaOperando);

    printf("%lf\n", result);

    destroiPilhaOperador(pilhaOperador);
    destroiPilhaOperando(pilhaOperando);
    return 0;
}

double calculadora(double num1, double num2, char op) {
    if (op == '+')
        return num1 + num2;
    if (op == '-')
        return num1 - num2;
    if (op == '*')
        return num1 * num2;
    if (op == '/')
        return num1 / num2;
}

int ehOperador(char carac) {
    if (carac == '+' || carac == '-' || carac == '*' || carac == '/')
        return 1;

    return 0;
}

int ehOperando(char carac) {
    if (carac >= '0' && carac <= '9')
        return 1;

    return 0;
}