#include <iostream>
using namespace std;

int main() {
    string word, hello = "hello";
    int i = 0, count = 0;

    cin >> word;

    for (int j = 0; j < word.size(); j++) {
        if (word[j] == hello[i]) {
            i++;
            count++;

            if (count == 5)
                break;
        }
    }

    if (count == 5)
        cout << "YES";
    else
        cout << "NO";
}