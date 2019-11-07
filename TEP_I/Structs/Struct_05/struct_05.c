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

racional soma(racional x, racional y){
    racional result;
    
    x = reduz(x.p, x.q);
    y = reduz(y.p, y.q);
    
    if(x.q == y.q){
        result.p = x.p + y.p;
        result.q = x.q;
        return result;
    }
    
    result.q = x.q * y.q;
    result.p = (x.p * y.q) + (y.p * x.q);
    
    result = reduz(result.p, result.q);
    
    return result;
}

racional produ(racional x, racional y){
    racional result;
    
    result.p = x.p * y.p;
    result.q = x.q * y.q;
    
    return reduz(result.p, result.q);
}

racional quoci(racional x, racional y){
    racional result;
    int aux;
            
    aux = y.p;
    y.p = y.q;
    y.q = aux;
    result = produ(x, y);
    
    return result;
}

int main() {
    int a, b, c, d;
    racional r1, r2, quo;
    scanf("%d%d%d%d", &r1.p, &r1.q, &r2.p, &r2.q);
    quo = quoci(r1, r2);
    printf("%d/%d", quo.p, quo.q);
    return 0;
}