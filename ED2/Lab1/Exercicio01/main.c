#include <stdio.h>

#include "crivoBit.h"
#include "crivoChar.h"
#include "crivoInt.h"

int main() {
    int num, i, j;

    // scanf("%d", &num);
    num = 10000;

    // CrivoInt* crivoInt = iniciaCrivoInt(num);
    // marcarPrimosCrivoInt(crivoInt, num);
    //destruirCrivoInt(crivoInt);

    // CrivoChar* crivoChar = iniciaCrivoChar(num);
    // marcarPrimosCrivoChar(crivoChar, num);
    // destruirCrivoChar(crivoChar);

    CrivoBit* crivoBit = iniciaCrivoBit(num);
    marcarPrimosCrivoBit(crivoBit, num);
    destruirCrivoBit(crivoBit);

    // for (i = 0; i <= num; i++) {
    //     if (!estaMarcadoCrivoBit(crivoBit, i))
    //         printf("%d, ", i);
    // }

    return 0;
}