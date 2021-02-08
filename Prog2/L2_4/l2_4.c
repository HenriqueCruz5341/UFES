 
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int num=1, maior, soma=0;
    float i=1, media;
    
    while(num != 0){
        scanf("%d", &num);
        
        if(num == 0){
            break;
        }
        
        if(i == 1){
            maior = num;
        }else if(num > maior){
            maior = num;
        }
        
        soma+= num;
        media = soma / i;
        
        printf("%d %.6f\n", maior, media);
        
        i++;
    }
}