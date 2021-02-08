 #include <stdio.h>

int main(){
    int num1, num2, result;
    
    scanf("%d%d", &num1, &num2);
    
    result = num1 - num2;
    
    if(result < 0){
        result *= -1;
    }
    
    printf("%d", result);
    
    return 0;
}
