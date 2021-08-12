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

        T[node] = T[2 * node] * T[2 * node + 1];  //trocou para multiplicação
    }
}

void build(int* T, int* A, int n) {
    buildRec(T, A, 1, 0, n - 1);
}

int queryRec(int* T, int node, int start, int end, int l, int r) {
    if (r < start or end < l) {
        return 1;  //o 1 é o número neutro da multiplicação
    }
    if (l <= start and end <= r) {
        return T[node];
    }

    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return (p1 * p2);  //trocou para multiplicação
}

int query(int* T, int n, int l, int r) {
    return queryRec(T, 1, 0, n - 1, l, r);
}

void updateRec(int* T, int* A, int node, int start, int end, int idx, int val) {
    if (start == end) {
        A[idx] = val;   //atribui o valor direto
        T[node] = val;  //atribui o valor direto
    } else {
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid) {
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }

        T[node] = T[2 * node] * T[2 * node + 1];  //trocou para multiplicação
    }
}

void update(int* T, int* A, int n, int idx, int val) {
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

int sgn(int n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}

void print_result(int num) {
    if (num == 0)
        cout << 0;
    else if (num < 0)
        cout << '-';
    else if (num > 0)
        cout << '+';
}

int main() {
    int n_numbers, n_rounds;
    int res;
    char command;
    int x, y, r;
    int i = 0;

    while (cin >> n_numbers) {
        if (i)
            cout << endl;
        cin >> n_rounds;

        int numbers[n_numbers];
        for (int j = 0; j < n_numbers; j++) {
            cin >> numbers[j];
            numbers[j] = sgn(numbers[j]);
        }

        int T[4 * n_numbers] = {0};
        build(T, numbers, n_numbers);

        for (int j = 0; j < n_rounds; j++) {
            cin >> command;
            if (command == 'P') {
                cin >> x;
                cin >> y;
                int n = query(T, n_numbers, x - 1, y - 1);
                print_result(n);
            } else if (command == 'C') {
                cin >> x;
                cin >> r;
                update(T, numbers, n_numbers, x - 1, sgn(r));
            }
        }
        i++;
    }
    cout << endl;
    return 0;
}