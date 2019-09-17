#include<stdio.h>

int main(){
 float base, altura, perimetro;

 scanf("%f", &base);
 scanf("%f", &altura);

 perimetro = 2*base + 2*altura;

 printf("%.2f", perimetro);

 return 0;
}
