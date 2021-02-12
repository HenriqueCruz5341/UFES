#include "crivoChar.h"

void iniciaCrivoChar(char* crivoChar, int num) {
    int i;

    for (i = 0; i <= num; i++)
        crivoChar[i] = '\0';
}

void marcarPrimosCrivoChar(char* crivoChar, int num) {
    int i, j;

    for (i = 2; i <= num; i++) {
        if (!crivoChar[i]) {
            for (j = i + 1; j <= num; j++) {
                if (!(j % i))
                    crivoChar[j] = 'h';
            }
        }
    }
}
