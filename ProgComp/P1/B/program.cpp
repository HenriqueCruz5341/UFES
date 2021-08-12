#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int num, i = 0;

    while (cin >> num) {
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    for (int& n : numbers) {
        if (i > 0) cout << '+';
        cout << n;
        i++;
    }

    return 0;
}