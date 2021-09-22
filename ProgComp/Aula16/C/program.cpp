#include <iostream>
using namespace std;

int main() {
    int qtd, n, k;

    cin >> qtd;

    while (qtd > 0) {
        cin >> n;
        cin >> k;

        int result = k + ((k - 1) / (n - 1));

        cout << result << endl;
        qtd--;
    }
}