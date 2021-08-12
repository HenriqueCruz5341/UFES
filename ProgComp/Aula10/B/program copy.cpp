#include <iostream>
#include <string>

using namespace std;

void buildRec(int* T, int* A, int node, int start, int end) {
    if (start == end) {
        T[node] = A[start];
    } else {
        int mid = (start + end) / 2;

        buildRec(T, A, 2 * node, start, mid);

        buildRec(T, A, 2 * node + 1, mid + 1, end);

        T[node] = T[2 * node] + T[2 * node + 1];
    }
}

void build(int* T, int* A, int n) {
    buildRec(T, A, 1, 0, n - 1);
}

int queryRec(int* T, int node, int start, int end, int l, int r) {
    if (r < start or end < l) {
        return 0;
    }
    if (l <= start and end <= r) {
        return T[node];
    }

    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int query(int* T, int n, int l, int r) {
    return queryRec(T, 1, 0, n - 1, l, r);
}

void updateRec(int* T, int* A, int node, int start, int end, int idx, int val) {
    if (start == end) {
        A[idx] += val;
        T[node] += val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid) {
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }

        T[node] = T[2 * node] + T[2 * node + 1];
    }
}

void update(int* T, int* A, int n, int idx, int val) {
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

int main() {
    int n_res = 0;
    int res;
    string command;
    int x, y, r;

    cin >> n_res;

    for (int i = 1; i < 4 && n_res != 0; i++) {
        if (i != 1) cout << endl;

        int resistors[n_res];
        for (int j = 0; j < n_res; j++) {
            cin >> res;
            resistors[j] = res;
        }

        int T[4 * n_res] = {0};
        build(T, resistors, n_res);

        cout << "Case " << i << ":" << endl;

        for (cin >> command; command != "END"; cin >> command) {
            if (command == "M") {
                cin >> x;
                cin >> y;
                cout << query(T, n_res, x - 1, y - 1) << endl;
            } else if (command == "S") {
                cin >> x;
                cin >> r;
                int aux = query(T, n_res, x - 1, x - 1);
                update(T, resistors, n_res, x - 1, r - aux);
            }
        }

        cin >> n_res;
    }

    return 0;
}