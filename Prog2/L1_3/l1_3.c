#include<stdio.h>

int main(){
 float coord1[2], coord2[2], perimetro;
 int i;

 for(i=0; i<2; i++){
  scanf("%f", &coord1[i]);
 }

 for(i=0; i<2; i++){
  scanf("%f", &coord2[i]);
 }

 perimetro = 2.0*(coord2[0] - coord1[0]) + 2.0*(coord2[1] - coord1[1]);

 printf("%.2f", perimetro);

 return 0;
}
