#include<stdio.h>

void potencia (int a, int b, int *pot){
    int i = 0;
    *pot = 1;
    
    for(i = 0; i < b; i++){
        *pot *= a;
    }
}
