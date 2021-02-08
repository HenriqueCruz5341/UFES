#include<stdio.h>
#include<string.h>

typedef struct {
    char intGrande[102];
} tIntGrande;

void LeNumero(tIntGrande *n) {
    scanf("%s", n->intGrande);
}

int AchaMaior(tIntGrande num1, tIntGrande num2) {
    int soma1 = 0, soma2 = 0, i;

    if (strlen(num1.intGrande) > strlen(num2.intGrande)) {
        return 1;
    } else if (strlen(num1.intGrande) < strlen(num2.intGrande)) {
        return 2;
    }

    for (i = 0; i < strlen(num1.intGrande); i++) {
        soma1 += num1.intGrande[i];
        soma2 += num2.intGrande[i];
    }

    if (soma1 > soma2) {
        return 1;
    } else if (soma1 < soma2) {
        return 2;
    } else {
        return 0;
    }
}

void SomarMaisUm(tIntGrande *n) {
    int tamanho = strlen(n->intGrande), i, j, k, flag = 1;

    if (n->intGrande[tamanho - 1] != '9') {
        n->intGrande[tamanho - 1]++;
    } else {
        for (i = tamanho - 1; i >= 0; i--) {
            if (n->intGrande[i] == '9') {
                n->intGrande[i] = '0';
                continue;
            } else {
                n->intGrande[i]++;
                if (i == 0) {
                }
                break;
            }
        }
    }

    for (i = 0; i < tamanho - 1; i++) {
        if (n->intGrande[i] != '0') {
            flag = 0;
        }
    }
    if (flag) {
        for (j = tamanho, k = tamanho - 1; k >= 0; j--, k--) {
            n->intGrande[j] = n->intGrande[k];
        }
        n->intGrande[0] = '1';
        n->intGrande[tamanho+1] = '\0';
    }
}

void ImprimirIntGrande(tIntGrande n) {
    printf("%s", n.intGrande);
}

int main() {
    tIntGrande num1;
    LeNumero(&num1);

    SomarMaisUm(&num1);

    ImprimirIntGrande(num1);

    return 0;
}

