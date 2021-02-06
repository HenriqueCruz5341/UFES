#include <stdio.h>

static int N;

void UF_init(int size, int* id) {
    N = size;
    for (int i = 0; i < N; i++) {
        id[i] = i;  // Cada objeto comeca na sua propria componente.
    }               // N acessos ao array.
}

int UF_find(int i, int* id) {
    while (i != id[i]) i = id[i];  // Buscar o pai ate a raiz.
    return i;                      // Profundidade de i acessos.
}

void UF_union(int p, int q, int* id) {
    int i = UF_find(p, id);  // Modifique raiz de p para a raiz de q.
    int j = UF_find(q, id);  // Profundidade de p+q acessos.
    id[i] = j;
}

int main() {
    int id[10];

    UF_init(10, id);
    UF_union(4, 3, id);
    UF_union(3, 8, id);
    UF_union(6, 5, id);
    UF_union(9, 4, id);
    UF_union(2, 1, id);
    UF_union(5, 0, id);
    UF_union(7, 2, id);
    UF_union(6, 1, id);
    UF_union(7, 3, id);
}