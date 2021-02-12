#include "crivoInt.h"

void iniciaCrivoInt(int* crivoInt, int num) {
    int i;

    for (i = 0; i <= num; i++)
        crivoInt[i] = 0;
}

void marcarPrimosCrivoInt(int* crivoInt, int num) {
    int i, j;

    for (i = 2; i <= num; i++) {
        if (!crivoInt[i]) {
            for (j = i + 1; j <= num; j++) {
                if (!(j % i))
                    crivoInt[j] = 1;
            }
        }
    }
}
