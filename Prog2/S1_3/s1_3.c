#include<stdio.h>

int main(){
int num1, num2, num3, n1, n2;
float media, dif1, dif2, dif3;

scanf("%d %d %d", &num1, &num2, &num3);

media = (num1 + num2 + num3) / 3.0;
//dif1 = num1 - media;
//dif2 = num2 - media;
//dif3 = num3 - media;

if((num1 > num2) && ((num2 > num3) || (num2 < num3))){
 dif1 = num1 - media;
 n1 = num1;
}else if((num2 > num3) && ((num3 > num1) || (num3 < num1))){
 dif1 = num2 - media;
 n1 = num2;
}else if((num3 > num2) && ((num2 > num1) || (num2 < num1))){
 dif1 = num3 - media;
 n1 = num3;
}

if((num1 < num2) && ((num2 < num3) || (num2 > num3))){
 dif2 = num1 - media;
 n2 = num1;
}else if((num2 < num3) && ((num3 < num1) || (num3 > num1))){
 dif2 = num2 - media;
 n2 = num2;
}else if((num3 < num2) && ((num2 < num1) || (num2 > num1))){
 dif2 = num3 - media;
 n2 = num3;
}

if(dif1 < 0){
 dif1 = dif1 * (-1);
}
if(dif2 < 0){
 dif2 = dif2 * (-1);
}

if(dif1 > dif2){
 printf("Media = %.2f - O %d eh o extremo mais proximo da media.", media, n1);
}else if(dif1 < dif2){
 printf("Media = %.2f - O %d eh o extremo mais proximo da media.", media, n2);
}else{
 printf("Media = %.2f - A distancia da media para os extremos eh %.2f.", media, dif1);
}

/*if((dif1 < dif2) && (dif1 < dif3)){
 printf("Media = %.2f - O %d eh o extremo mais proximo da media.", media, num1);
}else if((dif2 < dif1) && (dif1 < dif3)){
 printf("Media = %.2f - O %d eh o extremo mais proximo da media.", media, num2);
}else if((dif3 < dif2) && (dif2 < dif1)){
 printf("Media = %.2f - O %d eh o extremo mais proximo da media.", media, num3);
}else{
 printf("Media = %.2f - A distancia da media para os extremos eh %.2f.", media, dif1);
}*/



return 0;
}
