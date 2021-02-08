#include<stdio.h>

int main() {
    int i, num1, num2, maior;

    scanf("%d", &num1);

    for (i = 1; i <= num1; i += 2) {
        if (i != num1) {
            printf("%d", i);
        }
    }

    return 0;
}
