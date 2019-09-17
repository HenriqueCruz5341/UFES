 #include <stdio.h>

int main(){
    int numero;
    
    scanf("%d", &numero);
    
    if(numero < 0){
        numero *= -1;
    }
    
    printf("%d", numero);
    
    return 0;
}
