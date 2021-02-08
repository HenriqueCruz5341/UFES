 #include <stdio.h>

int main(){
    int num1, num2, result;
    
    scanf("%d%d", &num1, &num2);
    
    
    if(num2 == 0){
        printf("Indeterminado");
    }else{
        result = num1 % num2;
        if(result == 0){
            printf("Multiplo");
        }else{
            printf("Nao multiplo");
        }
    }
    
    return 0;
}
