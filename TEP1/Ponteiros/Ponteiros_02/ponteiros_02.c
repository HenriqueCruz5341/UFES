#include<stdio.h>

float tarifa(int h1, int m1, int h2, int m2, int *tempo){
    int minutos;
    float valorPag;
    
    minutos = (m2 - m1);
    *tempo = (h2 - h1);
    
    if(minutos > 15){
        (*tempo)++;
        valorPag = *tempo * 3;
    }else{
        valorPag = *tempo * 3;
    }
    
    return valorPag;
}
