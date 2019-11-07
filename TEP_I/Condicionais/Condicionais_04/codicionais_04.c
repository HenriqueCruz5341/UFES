 #include <stdio.h>

int main(){
    int num1, num2, result;
    
    scanf("%d%d", &num1, &num2);
    
    
    if(num2 > num1){
        printf("Acima do estoque");
    }else if(num1 == num2 && num1 != 0){
        printf("No limite");
    }else{
        printf("Abaixo do estoque");
    }
    return 0;
}
