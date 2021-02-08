#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {
    int linha, coluna, num, i, j, maior, posL, posC;

    scanf("%d %d", &linha, &coluna);

    for(i = 1; i <= linha; i++){
        for(j = 1; j <= coluna; j++){
            scanf("%d", &num);
            if(i == 1 && j == 1){
                maior = num;
            }
            if(num >= maior){
                maior = num;
                posL = i;
                posC = j;
            }
        }
    }

    printf("%d (%d, %d)", maior, posL, posC);

    return 0;
}
