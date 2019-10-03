#include<stdio.h>

typedef struct {
    int intGrande[100];
} tIntGrande;

void LeNumero(tIntGrande *n) {
    int num, i = 99;
    
    while(scanf("%1d", &num) == 1){
        n->intGrande[i] = num;
        i--;
    }
    
    while(i >= 0){
        n->intGrande[i] = 0;
    }
}


void ImprimirIntGrande(tIntGrande n) {
    int i = 0;
    
    while(n.intGrande[i] == 0){
        i++;
    }
    
    for(i; i < 100; i++){
        printf("%d", n.intGrande[i]);
    }
}

tIntGrande FatorialIntGrande(int num2){
    tIntGrande fat;
    int i = 0, j = 0, aux;
    
    for(j = 0; j < 100; j++){
        fat.intGrande[j] = 0;
    }
    fat.intGrande[99] = 1;
    
    while(num2 >= 1){
        
        for(i = 99; i >= 0; i--){
            fat.intGrande[i] *= num2;
        }
        
        for(i = 99; i >= 0; i--){
            if(fat.intGrande[i] > 9){
                aux = fat.intGrande[i] / 10;
                fat.intGrande[i-1] += aux;
                fat.intGrande[i] %= 10;
            }
        }
        
        num2--;
    }
    
    return fat;
}

int main() {
    tIntGrande num1, fat;
    int  num2;
    
    scanf("%d", &num2);

    fat = FatorialIntGrande(num2);

    ImprimirIntGrande(fat);

    return 0;
}
