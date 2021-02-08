#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int qtd, num, i, menor, pos = 0;

    scanf("%d", &qtd);

    if (qtd) {
        for (i = 1; i <= qtd; i++) {
            scanf("%d", &num);
            if(i == 1){
                menor  = num;
                pos = i;
            }
            if(num < menor){
                menor = num;
                pos = i;
            }
        }
        printf("POS:%d", pos);
    }
    
    return 0;
}
