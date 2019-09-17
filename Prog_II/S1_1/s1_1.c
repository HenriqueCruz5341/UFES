#include<stdio.h>

int main(){
float a, b, y[3];
float p1[2], p2[2], p3[2];

scanf("%f %f %f %f %f %f %f %f", &a, &b, &p1[0], &p1[1], &p2[0], &p2[1], &p3[0], &p3[1]);

y[0] = a*p1[0] + b;
y[1] = a*p2[0] + b;
y[2] = a*p3[0] + b;

if(y[0] > p1[1]){
 printf("(%.2f, %.2f) Abaixo da reta", p1[0], p1[1]);
}else if(y[0] < p1[1]){
 printf("(%.2f, %.2f) Acima da reta", p1[0], p1[1]);
}else {
 printf("(%.2f, %.2f) Na reta", p1[0], p1[1]);
}
printf(";\n");

if(y[1] > p2[1]){
 printf("(%.2f, %.2f) Abaixo da reta", p2[0], p2[1]);
}else if(y[1] < p2[1]){
 printf("(%.2f, %.2f) Acima da reta", p2[0], p2[1]);
}else {
 printf("(%.2f, %.2f) Na reta", p2[0], p2[1]);
}
printf(";\n");

if(y[2] > p3[1]){
 printf("(%.2f, %.2f) Abaixo da reta", p3[0], p3[1]);
}else if(y[2] < p3[1]){
 printf("(%.2f, %.2f) Acima da reta", p3[0], p3[1]);
}else {
 printf("(%.2f, %.2f) Na reta", p3[0], p3[1]);
}
printf(".\n");

return 0;
}
