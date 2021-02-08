#include <stdio.h>
#include <stdlib.h>

int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);
int EhNumero(char c);
int AnalisaSenha();

int main(int argc, char** argv) {
    int grupos, i, user, senha, grupoFor, grupoFra, grupoInv, maiorInv = -1, maiorFra = -1, maiorFor = -1,
            forte = 0, fraca = 0, invalida = 0;
    char lixo;

    scanf("%d", &grupos);

    for (i = 1; i <= grupos; i++) {
        printf("GRUPO %d\n", i);

        forte = 0;
        fraca = 0;
        invalida = 0;

        while (1) {
            scanf("%d", &user);
            if (user == -1) {
                break;
            }
            scanf("%c", &lixo);
            senha = AnalisaSenha();

            if (senha == 2) {
                forte++;
                printf("FORTE\n");
            }
            if (senha == 1) {
                fraca++;
                printf("FRACA\n");
            }
            if (senha == 0) {
                invalida++;
                printf("INVALIDA\n");
            }
        }
        if (forte > maiorFor) {
            grupoFor = i;
            maiorFor = forte;
        }
        if (fraca > maiorFra) {
            grupoFra = i;
            maiorFra = fraca;
        }
        if (invalida > maiorInv) {
            grupoInv = i;
            maiorInv = invalida;
        }
        if (i != grupos) {
            printf("\n");
        }
    }

    printf("FORTES: GRUPO(%d) QTD(%d)\n", grupoFor, maiorFor);
    printf("FRACAS: GRUPO(%d) QTD(%d)\n", grupoFra, maiorFra);
    printf("INVALIDAS: GRUPO(%d) QTD(%d)\n", grupoInv, maiorInv);

    return 0;
}

int EhLetraMaiuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int EhLetraMinuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

int EhNumero(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int AnalisaSenha() {
    char c;
    int cont = 0, lMai = 0, lMin = 0, num = 0, especial = 0;

    while (scanf("%c", &c) == 1 && c != ')') {
        if (EhLetraMaiuscula(c)) {
            lMai++;
        } else if (EhLetraMinuscula(c)) {
            lMin++;
        } else if (EhNumero(c)) {
            num++;
        } else {
            especial++;
        }

        cont++;

    }

    if (lMin && lMai && num && especial && cont >= 6) {
        return 2;
    } else if ((!lMin || !lMai || !num || !especial) && cont >= 6) {
        return 1;
    } else {
        return 0;
    }
}

