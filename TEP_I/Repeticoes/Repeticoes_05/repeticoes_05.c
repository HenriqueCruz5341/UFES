#include<stdio.h>

int main() {
    int i, num1, num2;

    scanf("%d %d", &num1, &num2);

    for (i = num1; i <= num2; i++) {
        if (!(i % 2)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
