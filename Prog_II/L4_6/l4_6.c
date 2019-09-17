#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int coordX;
    int coordY;
} tPonto;

typedef struct {
    tPonto pontoInicio;
    tPonto pontoFim;
} tReta;


tReta InicializaRetaPontos(tPonto pInicio, tPonto pFim);
tReta InicializaRetaEntrada();
void ImprimeReta(tReta reta);
tPonto PegaPontoInicio(tReta reta);
tPonto PegaPontoFim(tReta reta);
float ObtemTamanhoReta(tReta reta);
tPonto InicializaPonto(int x, int y);
tPonto LePonto();
void ImprimePonto(tPonto ponto);
int AlteraAbscissa(int x);
int AlteraOrdenada(int y);
int ObtemAbscissa(tPonto ponto);
int ObtemOrdenada(tPonto ponto);
tPonto MovimentaPontoDeltaX(tPonto ponto);
float CalculaDistancia(tPonto ponto1, tPonto ponto2);
int IdentificaQuadrante(tPonto ponto);
tPonto ObtemPontoSimetrico(tPonto ponto);

int main(int argc, char** argv) {
    tPonto ponto, pontoIniReta, pontoFimReta;
    tReta reta;
    int num, i;
    float distanciaInicio, distanciaFim;

    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        ponto = LePonto();
        reta = InicializaRetaEntrada();
        pontoIniReta = PegaPontoInicio(reta);
        pontoFimReta = PegaPontoFim(reta);
        distanciaInicio = CalculaDistancia(ponto, pontoIniReta);
        distanciaFim = CalculaDistancia(ponto, pontoFimReta);
        
        if(distanciaInicio < distanciaFim){
            printf("INICIO\n");
        }else if(distanciaFim < distanciaInicio){
            printf("FIM\n");
        }else{
            printf("EQUIDISTANTE\n");
        }
    }

    return 0;
}

tReta InicializaRetaPontos(tPonto pInicio, tPonto pFim){
    tReta reta;
    
    reta.pontoInicio = pInicio;
    reta.pontoFim = pFim;
    
    return reta;
}

tReta InicializaRetaEntrada(){
    tPonto pontoInicio, pontoFim;
    tReta reta;
    
    pontoInicio = LePonto();
    pontoFim  = LePonto();
    
    reta = InicializaRetaPontos(pontoInicio, pontoFim);
    return reta;
}

void ImprimeReta(tReta reta){
    
}

tPonto PegaPontoInicio(tReta reta){
    return reta.pontoInicio;
}

tPonto PegaPontoFim(tReta reta){
    return reta.pontoFim;
}

float ObtemTamanhoReta(tReta reta);

float CalculaDistancia(tPonto ponto1, tPonto ponto2){
    int x1, x2, y1, y2;
    float distancia;
    
    x1 = ObtemAbscissa(ponto1);
    x2 = ObtemAbscissa(ponto2);
    y1 = ObtemOrdenada(ponto1);
    y2 = ObtemOrdenada(ponto2);
    
    distancia = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
    return distancia;
}

tPonto InicializaPonto(int x, int y) {
    tPonto ponto;

    ponto.coordX = x;
    ponto.coordY = y;

    return ponto;
}

tPonto LePonto() {
    int x, y;
    tPonto ponto;

    scanf("%d %d", &x, &y);

    ponto = InicializaPonto(x, y);

    return ponto;
}

void ImprimePonto(tPonto ponto) {
    int x, y;

    x = ObtemAbscissa(ponto);
    y = ObtemOrdenada(ponto);
    
    printf("(%d,%d)", x, y);
}

int AlteraAbscissa(int x){
    return x * -1;
}

int AlteraOrdenada(int y){
    return y * -1;
}

int ObtemAbscissa(tPonto ponto) {
    return ponto.coordX;
}

int ObtemOrdenada(tPonto ponto){
    return ponto.coordY;
}

int IdentificaQuadrante(tPonto ponto){
    int x, y;
    
    x = ObtemAbscissa(ponto);
    y = ObtemOrdenada(ponto);
    
    if(x > 0 && y > 0){
        return 1;
    }else if(x < 0 && y > 0){
        return 2;
    }else if(x < 0 && y < 0){
        return 3;
    }else if(x > 0 && y < 0){
        return 4;
    }else{
        return 0;
    }
}

tPonto ObtemPontoSimetrico(tPonto ponto){
    int x, y;
    
    x = ObtemAbscissa(ponto);
    y = ObtemOrdenada(ponto);
    
    x = AlteraAbscissa(x);
    y = AlteraOrdenada(y);
    
    ponto = InicializaPonto(x, y);
    
    return ponto;
}
