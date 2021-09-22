#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int qtd;

    cin >> qtd;

    for (int cont = 0; cont < qtd; cont++) {
        int n, m, x, y;
        int total = 0;

        cin >> n >> m >> x >> y;

        char mat[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '.' && j + 1 < m && mat[i][j + 1] == '.') {
                    total += min(x * 2, y);
                    j++;
                } else if (mat[i][j] == '.')
                    total += x;
            }
        }

        cout << total << endl;
    }

    return 0;
}