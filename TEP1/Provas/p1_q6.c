#include<stdio.h>

struct numeroreal{
    int esquerda;
    int direita;
};
typedef struct numeroreal NumeroReal;

NumeroReal real_cria(int esq, int dir){
    NumeroReal numReal;
    
    if(dir < 0){
        dir = dir*(-1);
    }
    
    numReal.esquerda = esq;
    while(dir > 999){
        dir = dir / 10;
    }
    
    numReal.direita = dir;
    
    return numReal;
}

float real_converteFloat(NumeroReal numReal){
    float numFloat;
    
    numFloat = numReal.esquerda;
    
    if(numReal.esquerda < 0){
        numFloat -= (numReal.direita/1000.0);
    }else{
        numFloat += (numReal.direita/1000.0);
    }
    
    return numFloat;
}

NumeroReal real_soma(NumeroReal n1, NumeroReal n2){
    NumeroReal soma;
    float n1F, n2F, somaF;
    int esq, dir;
    
    n1F = real_converteFloat(n1);
    n2F = real_converteFloat(n2);
    
    somaF = n1F + n2F;
    esq = somaF;
    dir = (somaF * 1000);
    dir %= 1000;
    
    soma = real_cria(esq, dir);
    
    return soma;
}


NumeroReal real_subtrai(NumeroReal n1, NumeroReal n2){
    NumeroReal sub;
    float n1F, n2F, subF;
    int esq, dir;
    
    n1F = real_converteFloat(n1);
    n2F = real_converteFloat(n2);
    
    subF = n1F - n2F;
    esq = subF;
    dir = (subF * 1000);
    dir %= 1000;
    
    sub = real_cria(esq, dir);
    
    return sub;
}

NumeroReal real_multiplica(NumeroReal n1, NumeroReal n2){
    NumeroReal mult;
    float n1F, n2F, multF;
    int esq, dir;
    
    n1F = real_converteFloat(n1);
    n2F = real_converteFloat(n2);
    
    multF = n1F * n2F;
    esq = multF;
    dir = (multF * 1000);
    dir %= 1000;
    
    mult = real_cria(esq, dir);
    
    return mult;
}
