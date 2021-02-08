#include <stdio.h>
#include <stdlib.h>

char Codifica(char letra, int n);
char Decodifica(char letra, int n);
int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);

int main(int argc, char** argv) {
    int op, num, novaLetra, diferenca, aux, y = 0, i;
    char c = 'a', nova = 'a', lixo;

    scanf("%d", &op);
    switch (op) {
        case 1:
            scanf("%d", &num);
            scanf("%c", &lixo);
            while (c != '.') {
                scanf("%c", &c);
                if (EhLetra(c)) {
                    if (EhLetraMinuscula(c)) {
                        c = Codifica(c, num);
                    }else{
                        c = Codifica(c, num*2);
                    }
                    printf("%c", c);
                } else {
                    printf("%c", c);
                }
            }

            break;

        case 2:
            scanf("%d", &num);
            scanf("%c", &lixo);
            while (c != '.') {
                scanf("%c", &c);
                c = Decodifica(c, num);
                printf("%c", c);
            }

            break;

        default:
            printf("Operacao invalida.");
            break;
    }

    return 0;
}

char Codifica(char letra, int n) {
    int nova, constante;
    
    if(EhLetraMinuscula(letra)){
        constante = 96;
    }else{
        constante = 64;
    }

    //if (EhLetraMinuscula) {
        nova = letra - constante;
        if (n + nova > 26) {
            nova = (n + nova) % 26;
        } else {
            nova += n;
        }
        letra = nova + constante;
   /* } else {
        n = n * 2;
        nova = letra - 64;
        if (n + nova > 26) {
            nova = (n + nova) % 26;
        } else {
            nova += n;
        }
        letra = nova + 64;
    }*/
}

char Decodifica(char letra, int n) {
    int i, nova;

    if (letra >= 97 && letra <= 122) {
        nova = letra - 97;
        for (i = n; i >= 1; i--) {
            if (nova == 0) {
                nova = nova + 26;
            }
            if (i == n) {
                nova = nova - 1;
            } else {
                nova--;
            }

        }
        letra = nova + 97;
    }
}

int EhLetra(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return 1;
    } else {
        return 0;
    }
}

int EhLetraMaiuscula(char c) {

}

int EhLetraMinuscula(char c) {
    if (c >= 97 && c <= 122) {
        return 1;
    } else {
        return 0;
    }
}
