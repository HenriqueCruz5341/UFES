#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int len, dest;
    bool find = false;

    cin >> len >> dest;

    dest--;

    int cells[len];

    for (int i = 0; i < len; i++)
        cin >> cells[i];

    for (int i = 0; i < len; i += cells[i]) {
        if (i == dest) {
            find = true;
            break;
        }
    }

    if (find)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}