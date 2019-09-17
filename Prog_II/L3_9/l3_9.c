#include <stdio.h>
#include <math.h>

int verificapH(float pH); // 0-neutro; 1-acido; 2-basico
int verificaGotaChuvaAcida(float pH); // 1 se < 5.7
float porcentagem(float total, float valor);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

int main() {
    int area, densidade, tempo, i, qtdGotAc = 0, qtdGotBa = 0, qtdGotNe = 0, qtdGotChuvAc = 0;
    float phGota, pctGotAc, pctGotNo, qtdGota = 0, maAc = 8, maBa= -1, maNe = -1, aux, aux1;

    scanf("%d %d %d", &area, &densidade, &tempo);

    qtdGota = area * densidade * tempo;

    if (qtdGota) {
        for (i = 1; i <= qtdGota; i++) {
            scanf("%f", &phGota);

            if (verificapH(phGota) == 1) {
                qtdGotAc++;
            } else if (verificapH(phGota) == 2) {
                qtdGotBa++;
            } else {
                qtdGotNe++;
            }
            
            if(verificaGotaChuvaAcida(phGota)){
                qtdGotChuvAc++;
            }
            
            if(phGota <= maAc){
                maAc = phGota;
            }
            if(phGota >= maBa){
                maBa = phGota;
            }
            aux = fabs(7 - phGota);
            aux1 = fabs(7 - maNe);
            if(aux <= aux1){
                maNe = phGota;
            }
        }
        
        pctGotAc = porcentagem(qtdGota, qtdGotChuvAc);
        pctGotNo = 100 - pctGotAc;
        printf("%d %d %d %.2f %.2f %.2f\n", qtdGotAc, qtdGotBa, qtdGotNe, maAc, maBa, maNe);
        imprimeResultadosAnalise(pctGotAc, pctGotNo);
        
    } else {
        imprimeResultadosAnalise(0, 0);
    }
    
    return 0;
    
}

int verificapH(float pH) {
    if(pH > 7){
        return 2;  
    }else if(pH < 7){
        return 1;
    }else{
        return 0;
    }
}

int verificaGotaChuvaAcida(float pH) {
    if(pH <= 5.7){
        return 1;
    }else{
        return 0;
    }
}

float porcentagem(float total, float valor) {
    return (valor / total) * 100;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) {
    if(!porcentagemGotasChuvaAcida && !porcentagemGotasChuvaNormal){
        printf("Nenhuma gota foi avaliada");
    }else if(porcentagemGotasChuvaAcida >= 75){
        printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }else if(porcentagemGotasChuvaAcida <= 25){
        printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }else{
        printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    } 
}
