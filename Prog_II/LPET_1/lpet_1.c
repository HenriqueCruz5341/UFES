#include<stdio.h>

int main(){
 char nome[5];
 
 scanf("%s", &nome[0]);
 
 for(int i = 4; i>=0; i--){
 printf("%c", nome[i]);
 }
 printf("\n");

 return 0;
}
