#include <stdio.h>

int verify(int n, int* lin, int* col) {
    for (int i = 0; i < n; i++) {
        if ((lin[i] % 2) == 0 && (col[i] % 2) == 0) continue;
        return 0;
    }
    return 1;
}

int main() {
    int n;

    scanf("%d", &n);

    while (n > 0) {
        int mat[n][n];
        int lin[n];
        int col[n];
        int flag = 0;
        int ij[2];
        int cont = 0;
        int aux = -1;

        for (int i = 0; i < n; i++) {
            lin[i] = 0;
            col[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &mat[i][j]);
                if (mat[i][j]) {
                    lin[i]++;
                    col[j]++;
                }
            }
        }

        while (cont < (n * n)) {
            if (flag == 0 && verify(n, lin, col)) {
                flag = 1;
                break;
            } else {
                aux = mat[cont / n][cont % n];
                mat[cont / n][cont % n] = aux ? 0 : 1;
                for (int i = 0; i < n; i++) {
                    lin[i] = 0;
                    col[i] = 0;
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (mat[i][j]) {
                            lin[i]++;
                            col[j]++;
                        }
                    }
                }

                if (verify(n, lin, col)) {
                    flag = 2;
                    ij[0] = (cont / n) + 1;
                    ij[1] = (cont % n) + 1;
                    break;
                } else {
                    mat[cont / n][cont % n] = aux;
                }
            }
            cont++;
        }

        if (flag == 1)
            printf("OK\n");
        else if (flag == 2)
            printf("Change bit (%d,%d)\n", ij[0], ij[1]);
        else
            printf("Corrupt\n");

        scanf("%d", &n);
    }
}