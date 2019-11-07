#include<stdio.h>

int main() {
    int i;

    for (i = 1; i <= 300; i++) {
        if (!(i % 2)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
