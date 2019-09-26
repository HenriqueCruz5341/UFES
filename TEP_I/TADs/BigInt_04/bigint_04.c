#include<stdio.h>
#include<string.h>

typedef struct {
    char intGrande[101];
} tIntGrande;

void LeNumero(tIntGrande *n) {
    scanf("%s", n->intGrande);
}

int MaisDigitos(tIntGrande num1, tIntGrande num2){
    if (strlen(num1.intGrande) > strlen(num2.intGrande)) {
        return 1;
    } else if (strlen(num1.intGrande) < strlen(num2.intGrande)) {
        return 2;
    }
    return 0;
}

int AchaMaior(tIntGrande num1, tIntGrande num2) {
    int soma1 = 0, soma2 = 0, i;

    if (MaisDigitos(num1, num2) == 1) {
        return 1;
    } else if (MaisDigitos(num1, num2) == 2) {
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
    if (flag && tamanho != 1) {
        for (j = tamanho, k = tamanho - 1; k >= 0; j--, k--) {
            n->intGrande[j] = n->intGrande[k];
        }
        n->intGrande[0] = '1';
        n->intGrande[tamanho+1] = '\0';
    }
}

void TirarUm(tIntGrande *n){
    int tamanho = strlen(n->intGrande), i, j, k, flag = 1;

    if (n->intGrande[tamanho - 1] != '0') {
        n->intGrande[tamanho - 1]--;
    } else {
        for (i = tamanho - 1; i >= 0; i--) {
            if (n->intGrande[i] == '0') {
                n->intGrande[i] = '9';
                continue;
            } else {
                n->intGrande[i]--;
                if (i == 0) {
                }
                break;
            }
        }
    }
    if (n->intGrande[0] == '0' && tamanho != 1) {
        for (j = tamanho-2, k = tamanho - 1; j >= 0; j--, k--) {
            n->intGrande[j] = n->intGrande[k];
        }
        n->intGrande[0] = '9';
        n->intGrande[tamanho-1] = '\0';
    }
}

void ImprimirIntGrande(tIntGrande n) {
    printf("%s", n.intGrande);
}

tIntGrande SomarIntGrande(tIntGrande num1, tIntGrande num2){
    tIntGrande soma;
    int menorTamanho, i, maiorTamanho;
    
    if (MaisDigitos(num1, num2) == 1) {
        menorTamanho = strlen(num2.intGrande);
        maiorTamanho = strlen(num1.intGrande);
    } else if (MaisDigitos(num1, num2) == 2) {
        menorTamanho = strlen(num1.intGrande);
        maiorTamanho = strlen(num2.intGrande);
    }else{
        menorTamanho = strlen(num1.intGrande);
        maiorTamanho = strlen(num2.intGrande);
    }
    
    for(i = menorTamanho-1; i >= 0; i--){
        soma.intGrande[i] = ((num1.intGrande[i] - 48) + (num2.intGrande[i] - 48)) + 48;
    }
    soma.intGrande[maiorTamanho] = '\0';
    
    return soma;
}

int main() {
    tIntGrande num1, num2, soma;
    LeNumero(&num1);
    LeNumero(&num2);

    soma = SomarIntGrande(num1, num2);

    ImprimirIntGrande(soma);

    return 0;
}

