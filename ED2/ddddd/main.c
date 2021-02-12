#include <stdio.h>

#include "crivoBit.h"
#include "crivoChar.h"
#include "crivoInt.h"

int main() {
    int num, i, j;

    // scanf("%d", &num);
    num = 65300;
    // int crivoInt[num + 1];

    // iniciaCrivoInt(crivoInt, num);

    // marcarPrimosCrivoInt(crivoInt, num);

    // for (i = 0; i <= num; i++) {
    //     if (!crivoInt[i])
    //         printf("%d, ", i);
    // }

    // char crivoChar[num + 1];

    // iniciaCrivoChar(crivoChar, num);

    // marcarPrimosCrivoChar(crivoChar, num);

    // for (i = 0; i <= num; i++) {
    //     if (!crivoChar[i])
    //         printf("%d, ", i);
    // }

    CrivoBit* crivoBit = iniciaCrivoBit(num);

    marcarPrimosCrivoBit(crivoBit, num);

    // for (i = 0; i <= num; i++) {
    //     if (!estaMarcado(crivoBit, i))
    //         printf("%d, ", i);
    // }

    destruirCrivoBit(crivoBit);

    return 0;
}