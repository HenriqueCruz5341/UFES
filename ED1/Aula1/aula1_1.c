#include <stdio.h>

int main() {
    int var1, var2, var3, var4;
    int *pnt1, *pnt2, *pnt3, *pnt4;

    pnt1 = &var1;
    pnt2 = &var2;
    pnt3 = &var3;
    pnt4 = &var4;

    printf("==|Inserindo valor nas variaveis|==");
    printf("\nDigite o valor de var1: ");
    scanf("%d", &var1);
    printf("Digite o valor de var2: ");
    scanf("%d", &var2);
    printf("Digite o valor de var3: ");
    scanf("%d", &var3);
    printf("Digite o valor de var4: ");
    scanf("%d", &var4);
    printf("var1 = %d | var2 = %d | var3 = %d | var4 = %d\n", var1, var2, var3, var4);
    printf("==|Alterando o valor das variaveis utilizando ponteiros|==");
    printf("\nDigite o valor de pnt1: ");
    scanf("%d", pnt1);
    printf("Digite o valor de pnt2: ");
    scanf("%d", pnt2);
    printf("Digite o valor de pnt3: ");
    scanf("%d", pnt3);
    printf("Digite o valor de pnt4: ");
    scanf("%d", pnt4);
    printf("var1 = %d | var2 = %d | var3 = %d | var4 = %d\n", var1, var2, var3, var4);

    return 0;
}