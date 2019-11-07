#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i;

    scanf("%d", &num);
    for (i = 1; i <= 10; i++) {
        printf("%d x %2d = %2d\n", num, i, num*i);
    }

    return 0;
}