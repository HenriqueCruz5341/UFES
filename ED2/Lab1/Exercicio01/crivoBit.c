#include "crivoBit.h"

#include <stdio.h>
#include <stdlib.h>

struct crivoBit {
    char marcador;
};

CrivoBit* iniciaCrivoBit(int num) {
    int qtd = (++num / 8);
    int resto = num % 8 ? 1 : 0;
    int i;
    CrivoBit* novoCrivoBit = (CrivoBit*)malloc(sizeof(CrivoBit) * (qtd + resto));

    for (i = 0; i < qtd + resto; i++)
        novoCrivoBit[i].marcador = 0;
    return novoCrivoBit;
}

void marcarPrimosCrivoBit(CrivoBit* crivoBit, int num) {
    int i, j;

    for (i = 2; i <= num; i++) {
        if (!(crivoBit[i / 8].marcador & (1 << (i - 1) % 8))) {
            for (j = i + 1; j <= num; j++) {
                if (!(j % i))
                    crivoBit[j / 8].marcador |= (1 << (j - 1) % 8);
            }
        }
    }
}

char estaMarcadoCrivoBit(CrivoBit* crivoBit, int pos) {
    if (!(crivoBit[pos / 8].marcador & (1 << (pos - 1) % 8)))
        return '\0';

    return 'H';
}

void destruirCrivoBit(CrivoBit* crivoBit) {
    free(crivoBit);
}