#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int inicio, fim, i;

    scanf("%d %d", &inicio, &fim);

    printf("RESP:");
    
    for(i = inicio + 1; i < fim; i++){
        if(i % 2 == 0){
            printf("%d ", i);
        }
    }

}