#include<stdio.h>

int main(){
	char l1, l2, l3, n1, n2, n3, n4;
	int contL = 0, contN = 0;

	scanf("%c%c%c-%c%c%c%c", &l1, &l2, &l3, &n1, &n2, &n3, &n4);

	if((('a' <= l1 && l1 <= 'z') || ('A' <= l1 && l1 <= 'Z')) &&
	(('a' <= l2 && l2 <= 'z') || ('A' <= l2 && l2 <= 'Z')) &&
	(('a' <= l3 && l3 <= 'z') || ('A' <= l3 && l3 <= 'Z'))){
		contL++;
	}

	if(('0' <= n1 && n1 <= '9') && ('0' <= n2 && n2 <= '9') &&
	('0' <= n3 && n3 <= '9') && ('0' <= n4 && n4 <= '9')){
		contN++;
	}

	if (contL  == 1 && contN == 1) {
		printf("Codigo valido!");
	}else if (contL == 1 && contN == 0) {
		printf("Codigo invalido!Problema nos numeros!");
	}else if (contL == 0 && contN == 1) {
		printf("Codigo invalido!Problema nas letras!");
	}else if (contL == 0 && contN == 0) {
		printf("Codigo invalido!Problema nas letras e nos numeros!");
	}

	return 0;
}
