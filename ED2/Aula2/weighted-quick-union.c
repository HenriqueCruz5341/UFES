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
    while (i != id[i])
        i = id[i];  // Buscar o pai ate a raiz.
    return i;       // Profundidade de i acessos.
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
    int id[10], sz[10];

    UF_init(10, id, sz);
    UF_union(4, 3, id, sz);
    UF_union(3, 8, id, sz);
    UF_union(6, 5, id, sz);
    UF_union(9, 4, id, sz);
    UF_union(2, 1, id, sz);
    UF_union(5, 0, id, sz);
    UF_union(7, 2, id, sz);
    UF_union(6, 1, id, sz);
    UF_union(7, 3, id, sz);
}
