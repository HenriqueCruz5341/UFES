#include <stdio.h>

static int N;

void UF_init(int size, int *id, int *sz) {
    N = size;
    for (int i = 0; i < N; i++) {
        id[i] = i;  // Cada objeto comeca na sua propria componente.
        sz[i] = 1;
    }  // N acessos ao array.
}

int UF_find(int i, int *id) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];  // Buscar o pai ate a raiz.
    }
    return i;
}

void UF_union(int p, int q, int *id, int *sz) {
    int i = UF_find(p, id);  // Pendure a arvore menor sob a maior.
    int j = UF_find(q, id);  // Profundidade de ? acessos.
    if (i == j)
        return;
    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int main() {
    int id[16], sz[16];

    UF_init(16, id, sz);
    UF_union(0, 1, id, sz);
    UF_union(0, 2, id, sz);
    UF_union(0, 3, id, sz);
    UF_union(0, 4, id, sz);
    UF_union(1, 5, id, sz);
    UF_union(1, 6, id, sz);
    UF_union(1, 7, id, sz);
    UF_union(5, 11, id, sz);
    UF_union(5, 12, id, sz);
    UF_union(11, 15, id, sz);
    UF_union(6, 4, id, sz);
    UF_union(13, 4, id, sz);
    UF_union(2, 8, id, sz);
    UF_union(2, 9, id, sz);
    UF_union(8, 14, id, sz);
    UF_union(3, 10, id, sz);
    
    for(int i = 0; i < 16; i++){
        printf("Index: %d\n", i);
        printf("Parent: %d\n\n", id[i]);
    }  
}
