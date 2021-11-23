/*
BOJ 20040: 사이클 게임
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
int parent[500005];
int depth[500005];
int ans;

void init() {
    for (int i = 0; i < 500005; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    // x가 더 키가 크면 바꿔준다. (y가 더 크게)
    if (depth[x] > depth[y]) {
        swap(x, y);
    }
    parent[x] = y; // x를 y밑에 붙여준다.
    if (depth[x] == depth[y])
        depth[y]++;
}

bool is_cycle(int x, int y) {
    return find(x) == find(y);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (is_cycle(a, b)) {
            ans = i + 1;
            break;
        }
        merge(a, b);
    }
    cout << ans;
    return 0;
}