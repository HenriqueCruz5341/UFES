#include <stdio.h>
#include <stdlib.h>

#include "item.h"

extern void sort(Item* a, int lo, int hi);

int main(int argc, char const* argv[]) {
    int N = atoi(argv[1]);
    Item* itens = (Item*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
        scanf("%d", &itens[i]);

    sort(itens, 0, N - 1);
    // printf("\n");
    // for (int i = 0; i < N; i++)
    //     printf("%d ", itens[i]);

    free(itens);
    return 0;
}
