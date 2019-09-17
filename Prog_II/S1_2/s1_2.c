#include<stdio.h>

int main(){
float fun1, fun2, fun3;

scanf("%f %f %f", &fun1, &fun2, &fun3);

if((fun1 > fun2) && (fun2 > fun3)){
 printf("R$ %.2f\n", fun2);
} else if((fun1 > fun3) && (fun3 > fun2)){
 printf("R$ %.2f\n", fun3);
} else if((fun2 > fun1) && (fun1 > fun3)){
 printf("R$ %.2f\n", fun1);
} else if((fun2 > fun3) && (fun3 > fun1)){
 printf("R$ %.2f\n", fun3);
} else if((fun3 > fun1) && (fun1 > fun2)){
 printf("R$ %.2f\n", fun1);
}else if((fun3 > fun2) && (fun2 > fun1)){
 printf("R$ %.2f\n", fun2);
}


return 0;
}


