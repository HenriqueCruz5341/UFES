#include <stdio.h>
#include <stdlib.h>

int EhPrimo(int num);
int MaiorDigitoPrimo(int num);

int main(int argc, char** argv) {
    int qtd, num, i, maiorDigiPri, soma = 0;
        
    while(scanf("%d", &num) == 1){
        maiorDigiPri = MaiorDigitoPrimo(num);
        soma += maiorDigiPri;
    }
    
    printf("SOMA:%d", soma);
    
    return 0;
}


int EhPrimo(int num){
    int i, cont = 0;
    
    for(i = 1; i <= num; i++){
        if(num % i == 0){
            cont++;
        }
    }
    if(cont == 2){
        return 1;
    }else{
        return 0;
    }
}

int MaiorDigitoPrimo(int num){
    int maior = 0, digito;
    
    while(num > 0){
        digito = num % 10;
        num /= 10;
        if(EhPrimo(digito)){
            if(digito > maior){
                maior = digito;
            }
        }
    }
    
    return maior;
    
}
