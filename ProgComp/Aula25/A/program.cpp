#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> routers, vector<bool>& visited, int dest, stack<int>& m_stack) {
    int top = m_stack.top();
    if (top == dest) return;

    for (int i = 0; i < routers[top].size(); i++) {
        int aux = routers[top][i];
        if (!visited[aux]) {
            m_stack.push(aux);
            visited[aux] = true;
            dfs(routers, visited, dest, m_stack);
        }
        if (m_stack.top() == dest) return;
    }
    m_stack.pop();
}

int main() {
    int len;
    bool find = false;

    cin >> len;

    vector<vector<int>> routers(len);

    for (int i = 1; i < len; i++) {
        int router;
        cin >> router;
        routers[i].push_back(router - 1);
        routers[router - 1].push_back(i);
    }

    vector<bool> visited(len, false);
    vector<int> result;
    stack<int> m_stack;
    m_stack.push(0);
    visited[0] = true;

    dfs(routers, visited, len - 1, m_stack);

    while (!m_stack.empty()) {
        result.push_back(m_stack.top());
        m_stack.pop();
    }

    for (int i = result.size() - 1; i > -1; i--) {
        cout << (result[i] + 1);
        if (i != 0) cout << " ";
    }

    return 0;
}