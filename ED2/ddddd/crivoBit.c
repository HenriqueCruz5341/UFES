#include "crivoBit.h"

#include <stdlib.h>

struct crivoBit {
    unsigned marcador : 1;
};

CrivoBit* iniciaCrivoBit(int num) {
    CrivoBit* novoCrivoBit = (CrivoBit*)malloc(sizeof(CrivoBit) * (num + 1));
    int i;

    for (i = 0; i <= num; i++)
        novoCrivoBit[i].marcador = 0b0;

    return novoCrivoBit;
}

void marcarPrimosCrivoBit(CrivoBit* crivoBit, int num) {
    int i, j;

    for (i = 2; i <= num; i++) {
        if (crivoBit[i].marcador ^ 0b1) {
            for (j = i + 1; j <= num; j++) {
                if (!(j % i))
                    crivoBit[j].marcador = 0b1;
            }
        }
    }
}

char estaMarcado(CrivoBit* crivoBit, int pos) {
    if (crivoBit[pos].marcador ^ 0b1)
        return '\0';

    return 'H';
}

void destruirCrivoBit(CrivoBit* crivoBit) {
    free(crivoBit);
}

// void iniciaCrivoBit(unsigned char* crivoBit, int num) {
//     int i;

//     for (i = 0; i <= num; i++)
//         crivoBit[i] = 0b00000000;
// }

// void marcarPrimosCrivoBit(unsigned char* crivoBit, int num) {
//     int i, j;

//     for (i = 2; i <= num; i++) {
//         if (crivoBit[i] & 0) {
//             for (j = i + 1; j <= num; j++) {
//                 if (!(j % i))
//                     crivoBit[j] = 0b11111111;
//             }
//         }
//     }
// }
