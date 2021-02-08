#include<stdio.h>

int main(){
int num1, num2, contH = 0, contM = 0, invalido = 0;

scanf("%d %d", &num1, &num2);

if(1 <= num1 && num1 <= 5){
 contH++;
}else if(6 <= num1 && num1 <= 10){
 contM++;
}else{
 invalido = 1;
}

if(1 <= num2 && num2 <= 5){
 contH++;
}else if(6 <= num2 && num2 <= 10){
 contM++;
}else{
 invalido = 1;
}

if(invalido){
 printf("Invalido");
}else{
 if(contH == 2){
  if(num1 == num2){
   printf("Um homem");
  }else{
   printf("Par de homens");
  }
 }else if(contM == 2){
  if(num1 == num2){
   printf("Uma mulher");
  }else{
   printf("Par de mulheres");
  }
 }else{
  printf("Um casal");
 }
}

return 0;
}
