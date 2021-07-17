#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;

    cin >> word;

    while (word != "#") {
        if (next_permutation(word.begin(), word.end()))
            cout << word << endl;
        else
            cout << "No Successor" << endl;

        cin >> word;
    }
}