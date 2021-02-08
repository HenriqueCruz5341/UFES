#include <stdio.h>
#include <stdlib.h>

int ReduzInteiro(int n);
int MontaSenha(int senha, int dig);
int ReduzCodigo();


int main(int argc, char** argv) {
    char c;
    int numero;
    
    while(1){
        scanf("%c", &c);
        if(c == '.'){
            break;
        }
        if(c == '('){
            numero = ReduzCodigo();
        }
    }
    
    return 0;
}

int ReduzInteiro(int n){
    
}

int MontaSenha(int senha, int dig){
    
}

int ReduzCodigo(){
    int soma = 0, digito;
    
    while(scanf("%1d", &digito) == 1){
        soma += digito;
        
    }
    
    return soma;
}
