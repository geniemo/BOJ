#include <bits/stdc++.h>
#define ti3     tuple<int, int, int>
#define W       get<0>
#define X       get<1>
#define Y       get<2>
using namespace std;

int V, E;
int A, B, C;
ti3 edge[100005];
int parent[10005];
int depth[10005];

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (depth[x] > depth[y])
        swap(x, y);
    parent[x] = y;
    if (depth[x] == depth[y])
        depth[x]++;
}

bool isCycle(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
}

int kruskal() {
    int res = 0;
    for (int i = 0; i < E; i++) {
        if (!isCycle(X(edge[i]), Y(edge[i]))) {
            res += W(edge[i]);
            merge(X(edge[i]), Y(edge[i]));
        }
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    for (int i = 1; i <= V; i++)
        parent[i] = i;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        edge[i] = {C, A, B};
    }
    sort(edge, edge + E);
    cout << kruskal();
    return 0;
}