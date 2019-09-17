#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int t1, t2, t3, qtd, soma = 0, tipo, i;
    
    scanf("%d %d %d", &t1, &t2, &t3);
    
    scanf("%d", &qtd);
    
    for(i = 1; i <= qtd; i++){
        scanf("%d", &tipo);
        
        if(tipo == 1){
            soma += t1;
        }else if(tipo == 2){
            soma += t2;
        }else if(tipo == 3){
            soma += t3;
        }
    }
    
    printf("CUSTO:%d", soma);

    return 0;
}
