#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(int argc, char** argv) {
    Ponto *meuPonto;
    float x, y;
    
    x = 7.3f;
    y = 1.5f;
    
    meuPonto = pto_cria(4.2f, 8.6f);
    pto_imprime(meuPonto);
    
    pto_atribui(meuPonto, &x, &y);
    pto_imprime(meuPonto);
    return (0);
}

