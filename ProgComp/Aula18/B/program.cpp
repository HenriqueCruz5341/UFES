#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string a, s, r = "";
    pair<int, char> mn = {-1, '9'};
    int start_s = 0;

    cin >> a >> s;

    sort(s.begin(), s.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] < mn.second)
            mn = {i, a[i]};
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= mn.second)
            start_s++;
        else
            break;
    }

    for (int i = 0; i < a.size(); i++) {
        char dig = a[i];
        for (int j = start_s; j < s.size(); j++) {
            if (a[i] >= s[j])
                dig = a[i];
            else {
                dig = s[j];
                s[j] = '0';
            }
        }
        r += dig;
    }

    cout << r;
    // cout << mn.first << " " << mn.second << endl;
}