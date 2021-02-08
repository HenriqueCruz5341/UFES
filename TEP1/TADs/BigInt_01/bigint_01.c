#include<stdio.h>
#include<string.h>

typedef struct{
    char intGrande[101];
}tIntGrande;

void LeNumero(tIntGrande *n){
    scanf("%s", n->intGrande);
}

int AchaMaior(tIntGrande num1, tIntGrande num2){
    int soma1 = 0, soma2 = 0, i;
    
    if(strlen(num1.intGrande) > strlen(num2.intGrande)){
        return 1;
    }else if(strlen(num1.intGrande) < strlen(num2.intGrande)){
        return 2;
    }
    
    for(i = 0; i < strlen(num1.intGrande); i++){
        soma1 += num1.intGrande[i];
        soma2 += num2.intGrande[i];
    }
    
    if(soma1 > soma2){
        return 1;
    }else if(soma1 < soma2){
        return 2;
    }else{
        return 0;
    }
}

int main(){
    tIntGrande num1, num2;
    int verificador;
    LeNumero(&num1);
    LeNumero(&num2);
    
    verificador = AchaMaior(num1, num2);
    
    if(verificador == 1){
        printf("MAIOR");
    }else if(verificador == 2){
        printf("MENOR");
    }else{
        printf("IGUAL");
    }
    
    return 0;
}
