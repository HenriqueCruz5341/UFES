#include <iostream>
#include <string>

using namespace std;

int main() {
    const int max_n = 1e6 + 10;
    int qtd, juicy, label;

    cin >> qtd;

    int piles[max_n], pile, init = 0, sum = 0;

    for (int i = 0; i < qtd; i++) {
        cin >> pile;
        sum += pile;
        for (int j = init; j < sum; j++)
            piles[j] = i + 1;
        init = sum;
    }

    cin >> juicy;

    for (int i = 0; i < juicy; i++) {
        cin >> label;
        cout << piles[label - 1] << endl;
    }

    return 0;
}