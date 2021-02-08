#include<stdio.h>

int main() {
    int i, num1, num2, maior;

    scanf("%d %d", &num1, &num2);
    
    if(num1 > num2){
        maior = num2;
        num2 = num1;
        num1 = maior;
    }

    for (i = num1; i <= num2; i++) {
        if (!(i % 2)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
