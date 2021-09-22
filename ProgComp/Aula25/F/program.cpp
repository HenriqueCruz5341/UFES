#include <iostream>
#include <vector>

using namespace std;

const int INIT = 0;
const int RED = 1;
const int GREEN = 2;

int main() {
    int v, a;
    cin >> v;

    while (v > 0) {
        bool flag = false;
        int src, dest;
        vector<vector<int>> graph(v);
        vector<int> colors(v, INIT);

        cin >> a;

        for (int i = 0; i < a; i++) {
            cin >> src >> dest;
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }

        colors[0] = RED;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (colors[graph[i][j]] == INIT) {
                    if (colors[i] == RED)
                        colors[graph[i][j]] = GREEN;
                    else if (colors[i] == GREEN)
                        colors[graph[i][j]] = RED;
                } else if (colors[graph[i][j]] == colors[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag)
            cout << "NOT BICOLORABLE." << endl;
        else
            cout << "BICOLORABLE." << endl;

        cin >> v;
    }
}