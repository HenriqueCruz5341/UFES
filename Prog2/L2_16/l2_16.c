#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int num, menor, pos1 = -1, pos2 = 0, i = 0, j = 0;
    char lixo;
    
    while(scanf("%d", &num)){
        if(i == 0){
            menor = num;
        }
        if(menor >= num){
            menor = num;
        }
        i++;
    }
    scanf("%c", &lixo);
    while(scanf("%d", &num)){
        if(pos1 == -1 && menor == num){
            pos1 = j;
        }
        if(pos1 != -1 && menor == num){
            pos2 = j;
        }
        j++;
    }
    
    if(pos2 == 0){
        pos1 = j;
        pos2 = j;
    }
    
    printf("%d %d %d", menor, pos1, pos2);
    
    return 0;
} 
