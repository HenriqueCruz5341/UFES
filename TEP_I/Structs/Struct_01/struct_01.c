#include <stdio.h>

/* 
   Racional de qualquer numero da forma p/q, sendo p inteiro e q inteiro nao nulo. Vamos
   convencionar que o campo q de todo racional eh estritamente positivo e que o maximo 
   divisor comum dos campos p e q eh 1.   
 */

typedef struct r {
    int p, q;
} racional;

int testeSinal(int a, int b) {
    if (a < 0 && b > 0) {
        return 1;
    } else if (a > 0 && b < 0) {
        return 2;
    } else if (a < 0 && b < 0) {
        return 3;
    } else {
        return 4;
    }
}

int maior(int a, int b){
    int maior;
    
    if(a < b){
        maior = b;
    }else{
        maior = a;
    }
    
    if(maior < 0){
        return maior *= -1;
    }
    
    return maior;
}

racional reduz(int a, int b) {
    racional rac;

    int divisivel = 1, i = 1, divisor;
    
    while (i <= maior(a,b)) {
        if (a % i == 0 && b % i == 0) {
            divisor = i;
        }
        i++;
    }
    rac.p = a / divisor;
    rac.q = b / divisor;

    if (testeSinal(a,b) == 1 || testeSinal(a,b) == 4) {
        return rac;
    } else if (testeSinal(a,b) == 2 || testeSinal(a,b) == 3) {
        rac.p *= -1;
        rac.q *= -1;
        return rac;
    }


}

int main() {
    int a, b;
    racional r;
    scanf("%d%d", &a, &b);
    r = reduz(a, b);
    printf("%d/%d", r.p, r.q);
    return 0;
}
