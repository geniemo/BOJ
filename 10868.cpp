#include <bits/stdc++.h>
using namespace std;

int N, M;
int a, b;

int num[100'005];
int tree[100'005 * 4];

int init(int node, int node_l, int node_r) {
    if (node_l == node_r)
        return tree[node] = num[node_l];
    int mid = (node_l + node_r) / 2;
    return tree[node] = min(init(node * 2, node_l, mid), init(node * 2 + 1, mid + 1, node_r));
}

// [a, b] 사이의 최솟값을 반환
int seg_min(int node, int node_l, int node_r) {
    if (b < node_l || node_r < a)
        return 0x7f7f7f7f;
    if (a <= node_l && node_r <= b)
        return tree[node];
    int mid = (node_l + node_r) / 2;
    return min(seg_min(node * 2, node_l, mid), seg_min(node * 2 + 1, mid + 1, node_r));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, 1, N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << seg_min(1, 1, N) << "\n";
    }
    return 0;
}