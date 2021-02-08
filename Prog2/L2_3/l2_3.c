#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int i, num, par=0, impar=0, menor=0, maior=0, soma=0;
    float qtd, media;
    
    scanf("%f", &qtd);
    
    for(i = 0; i < qtd; i++){
        scanf("%d", &num);
        
        if(i == 0){
            menor = num;
            maior = num;
        }else if(num > maior){
            maior = num;
        }else if(num < menor){
            menor = num;
        }
        
        if(num % 2 == 0){
            par++;
        }else {
            impar++;
        }
        
        soma+= num;
       
    }
    
    media = soma/qtd;
    
    printf("%d %d %d %d %.6f", maior, menor, par, impar, media);
    
}