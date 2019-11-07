#include<stdio.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;


data leData (){
    data date;
    
    scanf("%d %d %d", &date.dia, &date.mes, &date.ano);
    
    return date;
}

void imprimeData (data atual){
    printf("A data informada eh %02d/%02d/%04d.", atual.dia, atual.mes, atual.ano);
}
