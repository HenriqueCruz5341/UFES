#include<stdio.h>


int main(){
    int numero;
    
    scanf("%d", &numero);
    
    if(numero % 2){
        printf("O numero %d eh impar", numero);
    }else{
        printf("O numero %d eh par", numero);
    }
    
    return 0;
}