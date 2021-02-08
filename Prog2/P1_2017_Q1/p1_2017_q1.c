#include<stdio.h>

int main(){
int num1, num2, result;
char op;

scanf("%d %d %c", &num1, &num2, &op);

switch (op){
 case '+':
  result = num1 + num2;
  printf("RESP:%d", result);
 break;

 case '-':
  result = num1 - num2;
  printf("RESP:%d", result);
 break;

 case '*':
  result = num1 * num2;
  printf("RESP:%d", result);
 break;

 case '/':
  result = num1 / num2;
  printf("RESP:%d", result);
 break;

 default:
  printf("Invalido");
 break;
}

return 0;
}
