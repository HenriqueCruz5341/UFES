#include <algorithm>
#include <cstdio>
#define MAX 100010
using namespace std;

int a[MAX], SegTree[4 * MAX];
int i, j, n, k, z, q, pos, value;
char c;

int sgn(int n) {
    return (n > 0) - (n < 0);
}

void BuildTree(int *a, int Vertex, int Left, int Right) {
    if (Left == Right)
        SegTree[Vertex] = a[Left];
    else {
        int Middle = (Left + Right) / 2;
        BuildTree(a, 2 * Vertex, Left, Middle);
        BuildTree(a, 2 * Vertex + 1, Middle + 1, Right);
        SegTree[Vertex] = SegTree[2 * Vertex] * SegTree[2 * Vertex + 1];
    }
}

void Update(int Vertex, int LeftPos, int RightPos,
            int Position, int NewValue) {
    if (LeftPos == RightPos)
        SegTree[Vertex] = NewValue;
    else {
        int Middle = (LeftPos + RightPos) / 2;
        if (Position <= Middle)
            Update(2 * Vertex, LeftPos, Middle, Position, NewValue);
        else
            Update(2 * Vertex + 1, Middle + 1, RightPos, Position, NewValue);
        SegTree[Vertex] = SegTree[2 * Vertex] * SegTree[2 * Vertex + 1];
    }
}

int Query(int Vertex, int LeftPos, int RightPos, int Left, int Right) {
    if (Left > Right)
        return 1;
    if ((Left == LeftPos) && (Right == RightPos))
        return SegTree[Vertex];
    int Middle = (LeftPos + RightPos) / 2;
    return Query(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle)) *
           Query(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main(void) {
    while (scanf("%d %d", &n, &k) == 2) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] = sgn(a[i]);
        }

        BuildTree(a, 1, 1, n);

        for (z = 0; z < k; z++) {
            scanf("\n%c", &c);
            if (c == 'C') {
                scanf("%d %d\n", &pos, &value);
                value = sgn(value);
                Update(1, 1, n, pos, value);
            } else {
                scanf("%d %d\n", &i, &j);
                q = Query(1, 1, n, i, j);
                if (q == 1)
                    printf("+");
                else if (q == 0)
                    printf("0");
                else
                    printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
