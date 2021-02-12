#include "crivoInt.h"

#include <stdlib.h>

struct crivoInt {
    int marcador;
};

CrivoInt* iniciaCrivoInt(int num) {
    CrivoInt* novoCrivoInt = (CrivoInt*)malloc(sizeof(CrivoInt) * (num + 1));
    int i;

    for (i = 0; i <= num; i++)
        novoCrivoInt[i].marcador = 0;

    return novoCrivoInt;
}

void marcarPrimosCrivoInt(CrivoInt* crivoInt, int num) {
    int i, j;

    for (i = 2; i <= num; i++) {
        if (!crivoInt[i].marcador) {
            for (j = i + 1; j <= num; j++) {
                if (!(j % i))
                    crivoInt[j].marcador = 1;
            }
        }
    }
}

char estaMarcadoCrivoInt(CrivoInt* crivoInt, int pos) {
    if (!crivoInt[pos].marcador)
        return '\0';

    return 'H';
}

void destruirCrivoInt(CrivoInt* crivoInt) {
    free(crivoInt);
}
