#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i;

    scanf("%d", &num);
    if (num) {
        printf("Os %d primeiros numeros pares sao:", num);

        for (i = 2; i <= num * 2; i += 2) {
            printf(" %d", i);
        }
    }

    return 0;
}