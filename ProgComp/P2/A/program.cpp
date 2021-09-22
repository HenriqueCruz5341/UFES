#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#include <queue>

using namespace std;

priority_queue<char> pq_i;
priority_queue<char> pq_r;

int main() {
    string input;
    string replace;
    cin >> input;
    cin >> replace;

    for (int i = 0; i < replace.length(); i++) {
        pq_r.push(replace[i]);
    }

    for (int i = 0; i < input.length(); i++) {
        if (input[i] < pq_r.top() && !pq_r.empty()) {
            input[i] = pq_r.top();
            pq_r.pop();
        }
    }

    cout << input;

    return 0;
}