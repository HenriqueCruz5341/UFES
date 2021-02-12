#include <stdio.h>

#include "crivoBit.h"
#include "crivoChar.h"
#include "crivoInt.h"

int main() {
    int num, i, j;

    // scanf("%d", &num);
    num = 65300;

    // CrivoInt* crivoInt = iniciaCrivoInt(num);

    // marcarPrimosCrivoInt(crivoInt, num);

    // for (i = 0; i <= num; i++) {
    //     if (!estaMarcado(crivoInt, i))
    //         printf("%d, ", i);
    // }
    // destruirCrivoInt(crivoInt);

    // CrivoChar* crivoChar = iniciaCrivoChar(num);

    // marcarPrimosCrivoChar(crivoChar, num);

    // // for (i = 0; i <= num; i++) {
    // //     if (!estaMarcado(crivoChar, i))
    // //         printf("%d, ", i);
    // // }
    // destruirCrivoChar(crivoChar);

    CrivoBit* crivoBit = iniciaCrivoBit(num);

    marcarPrimosCrivoBit(crivoBit, num);

    // // for (i = 0; i <= num; i++) {
    // //     if (!estaMarcado(crivoBit, i))
    // //         printf("%d, ", i);
    // // }
    destruirCrivoBit(crivoBit);

    return 0;
}