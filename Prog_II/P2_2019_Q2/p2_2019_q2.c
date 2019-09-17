#include <stdio.h>
#include <stdlib.h>

int EhFinalDaLista(int buraco);
int EcontraMaiorBuraco();
int ContaEsferasGrandes(int maiorBuraco);

int main(int argc, char** argv) {
    int maiorBuraco, qtdEsferas = 0;
    
    maiorBuraco = EcontraMaiorBuraco();
    qtdEsferas = ContaEsferasGrandes(maiorBuraco);
    
    printf("QTD:%d", qtdEsferas);
            
    return 0;
}


int EhFinalDaLista(int buraco){
    if(buraco == -1){
        return 0;
    }else{
        return 1;
    }
}

int EcontraMaiorBuraco(){
    int buraco, maior = 0;
    
    while(scanf("%d", &buraco) == 1 && EhFinalDaLista(buraco)){
        if(buraco > maior){
            maior = buraco;
        }
    }
    
    return maior;
}

int ContaEsferasGrandes(int maiorBuraco){
    int esfera, cont = 0;
    
    while(scanf("%d", &esfera) == 1 && EhFinalDaLista(esfera)){
        if(esfera >= maiorBuraco){
            cont++;
        }
    }
    
    return cont;
}

