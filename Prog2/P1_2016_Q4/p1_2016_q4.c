#include<stdio.h>

int main(){
int num1, num2, num3;

scanf("%d %d %d", &num1, &num2, &num3);

num1 = (num1 / 100) % 10;
num2 = (num2 / 100) % 10;
num3 = (num3 / 100) % 10;

if(num1 && num2 && num3){
 if(num1 <= num2 && num1 <= num3){
  printf("N1");
 } else if(num2 <= num1 && num2 <= num3){
  printf("N2");
 }else{
  printf("N3");
 }
}else if(!num1 && num2 && num3){
 if(num2 <= num3){
  printf("N2");
 }else{
  printf("N3");
 }
}else if(num1 && !num2 && num3){
 if(num1 <= num3){
  printf("N1");
 }else{
  printf("N3");
 }
}else if(num1 && num2 && !num3){
 if(num2 <= num1){
  printf("N2");
 }else{
  printf("N1");
 }
}else if(!num1 && !num2 && num3){
  printf("N3");
}else if(!num1 && num2 && !num3){
 printf("N2");
}else if(num1 && !num2 && !num3){
 printf("N1");
}else{
 printf("Nenhum");
}

//printf("%d %d %d", num1, num2, num3);



return 0;
}
