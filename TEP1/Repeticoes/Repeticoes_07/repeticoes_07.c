#include<stdio.h>

int main() {
    int i, num1, num2, maior;

    scanf("%d %d", &num1, &num2);

    for (i = 0; i <= num1; i += num2) {
        printf("%d", i);
    }

    return 0;
}
