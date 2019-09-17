#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

tData LeData();
void ImprimeData(tData data);
void VarrerDatas(tData dataI, tData dataF);
int MesImpar(tData data);
tData MudarDia(tData inicio, tData fim, int dias);
tData MudarMes(tData inicio);
tData MudarAno(tData inicio);
int ComparaDatas(tData d1, tData d2);

int main(int argc, char** argv) {
    tData dataIni, dataFim;

    dataIni = LeData();
    dataFim = LeData();

    VarrerDatas(dataIni, dataFim);

    return 0;
}

tData LeData() {
    tData data;

    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

    return data;
}

void ImprimeData(tData data) {
    printf("'%d/%d/%d'\n", data.dia, data.mes, data.ano);
}

void VarrerDatas(tData dataI, tData dataF) {
    int i;

    while (!ComparaDatas(dataI, dataF)) {
        if (dataI.mes < 8) {
            if (MesImpar(dataI)) {
                dataI = MudarDia(dataI, dataF, 31);
            } else {
                dataI = MudarDia(dataI, dataF, 30);
            }
        } else {
            if (MesImpar(dataI)) {
                dataI = MudarDia(dataI, dataF, 30);
            } else {
                dataI = MudarDia(dataI, dataF, 31);
            }
        }
    }
}

int MesImpar(tData data) {
    if (data.mes % 2) {
        return 1;
    } else {
        return 0;
    }
}

tData MudarDia(tData inicio, tData fim, int dias) {
    int flag = 0;

    while (inicio.dia < dias) {
        if (ComparaDatas(inicio, fim)) {
            break;
            flag = 0;
        }
        inicio.dia++;
        ImprimeData(inicio);
        flag++;
    }
    if (!ComparaDatas(inicio, fim) && flag && inicio.dia == dias) {
        inicio = MudarMes(inicio);
        inicio.dia = 1;
        if (!ComparaDatas(inicio, fim) && inicio.mes == 13) {
            inicio = MudarAno(inicio);
            inicio.mes = 1;
            ImprimeData(inicio);
        }else{
            ImprimeData(inicio);
        }
    }

    return inicio;
}

tData MudarMes(tData inicio) {
    inicio.mes++;
    return inicio;
}

tData MudarAno(tData inicio) {
    inicio.ano++;
    return inicio;
}

int ComparaDatas(tData d1, tData d2) {
    if (d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano) {
        return 1;
    } else {
        return 0;
    }
}
