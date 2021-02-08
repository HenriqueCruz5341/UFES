#include <stdio.h>
#include <stdlib.h>

int QtdDebitoPlaca(int presc);
int MaiorDebitoCidade();

int main(int argc, char** argv) {
    int qtdCid, i, maiorDeb, soma = 0;

    scanf("%d", &qtdCid);

    for (i = 1; i <= qtdCid; i++) {
        maiorDeb = MaiorDebitoCidade();
        soma += maiorDeb;
    }
    
    printf("SOMA:%d\n", soma);
    
    return 0;
}

int QtdDebitoPlaca(int presc) {
    int valor = 0, prescPla = 0, soma = 0;
    
    while(scanf("(%d:%d)", &valor, &prescPla) == 2){
        if(prescPla <= presc){
            soma += valor;
        }
    }
    
    return soma;
}

int MaiorDebitoCidade() {
    int presc, qtdDebPlaca, maiorDeb = 0;
    char l1, l2, l3, ml1, ml2, ml3, lixo;

    scanf("%d", &presc);
    
    
    while (1) {
        scanf("%c", &lixo);
        scanf("%c%c%c", &l1, &l2, &l3);
        if (l1 == 'F' && l2 == 'I' && l3 == 'M') {
            break;
        }

        qtdDebPlaca = QtdDebitoPlaca(presc);

        if (qtdDebPlaca > maiorDeb) {
            maiorDeb = qtdDebPlaca;
            ml1 = l1;
            ml2 = l2;
            ml3 = l3;
        }

    }
    if (maiorDeb) {
        printf("PLACA:%c%c%c DEBITO:%d\n", ml1, ml2, ml3, maiorDeb);
    }else{
        printf("SEM DEBITO!\n");
    }
    
    return maiorDeb;
}
