#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;
using ll = long long;

int N, M, K;
int num[1'000'005];
ll tree[1'000'005 * 4];
int a, b, c;

// tree[node]는 st ~ en을 담당
ll init(int node, int st, int en) {
    if (st == en)
        return tree[node] = num[st];
    int mid = (st + en) / 2;
    return tree[node] = (init(node * 2, st, mid) * init(node * 2 + 1, mid + 1, en)) % mod; 
}

// b번째 값을 c로 변경
ll update(int node, int st, int en) {
    // b번째 값을 범위에 포함하지 않는 노드는 부모 노드에 곱해줘야 하기 때문에 그대로 반환
    if (b < st || en < b)
        return tree[node];
    // 리프 노드는 c로 변경
    if (st == en)
        return tree[node] = c;
    int mid = (st + en) / 2;
    return tree[node] = (update(node * 2, st, mid) * update(node * 2 + 1, mid + 1, en)) % mod;
}

// b번째 수부터 c번째 수까지의 곱을 반환
ll mul(int node, int st, int en) {
    if (en < b || c < st)
        return 1;
    if (b <= st && en <= c)
        return tree[node];
    int mid = (st + en) / 2;
    return (mul(node * 2, st, mid) * mul(node * 2 + 1, mid + 1, en)) % mod;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, 1, N);
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        switch (a) {
        case 1:
            update(1, 1, N);
            num[b] = c;
            break;
        case 2:
            cout << mul(1, 1, N) << "\n";
        }
    }
    return 0;
}