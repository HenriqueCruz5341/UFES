#include "crivoChar.h"

#include <stdlib.h>

struct crivoChar {
    char marcador;
};

CrivoChar* iniciaCrivoChar(int num) {
    CrivoChar* novoCrivoChar = (CrivoChar*)malloc(sizeof(CrivoChar) * (num + 1));
    int i;

    for (i = 0; i <= num; i++)
        novoCrivoChar[i].marcador = '\0';

    return novoCrivoChar;
}

void marcarPrimosCrivoChar(CrivoChar* crivoChar, int num) {
    int i, j;

    for (i = 2; i <= num; i++) {
        if (!crivoChar[i].marcador) {
            for (j = i + 1; j <= num; j++) {
                if (!(j % i))
                    crivoChar[j].marcador = 'H';
            }
        }
    }
}

char estaMarcadoCrivoChar(CrivoChar* crivoChar, int pos) {
    if (!crivoChar[pos].marcador)
        return '\0';

    return 'H';
}

void destruirCrivoChar(CrivoChar* crivoChar) {
    free(crivoChar);
}