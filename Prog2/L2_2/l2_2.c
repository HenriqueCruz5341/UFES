#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int inicio, fim, i;
    
    scanf("%d %d", &inicio, &fim);
    
    for(i = inicio + 1; i < fim; i++){
        if(i % 3 == 0){
            printf("%d ", i);
        }else if(i % 4 == 0){
            printf("%d ", i);
        }else if(i % 7 == 0){
            printf("%d ", i);
        }
    }
}