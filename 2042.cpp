#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N, M, K;
ll num[1000001];
ll tree[1000001 * 4];

ll init(int node, int st, int en) {
    // 리프 노드일 때
    if (st == en)
        return tree[node] = num[st];
    // 리프 노드가 아니라면 왼쪽 자식과 오른쪽 자식으로 나눈다
    int mid = (st + en) / 2;
    return tree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, en);
}

// node: 노드 번호, st~en: 현재 노드가 합으로 갖는 데이터들의 범위, idx번째 값을 dif만큼 변경
void update(int node, int st, int en, int idx, ll dif) {
    if (idx < st || en < idx)
        return;
    tree[node] += dif;
    if (st == en) return;
    int mid = (st + en) / 2;
    update(node * 2, st, mid, idx, dif);
    update(node * 2 + 1, mid + 1, en, idx, dif);
}


// node: 노드 번호, st~en: 현재 노드가 합으로 갖는 데이터들의 범위, l~r: 구하려는 구간
ll sum(int node, int st, int en, int l, int r) {
    // 구해야 하는 범위의 어느 부분도 포함되어 있지 않을 때
    if (en < l || r < st)
        return 0;
    // 구해야 하는 범위 속에 포함되어 있을 때
    if (l <= st && en <= r)
        return tree[node];
    // st~en과 l~r이 교차되어 겹쳐져 있을 때
    int mid = (st + en) / 2;
    return sum(node * 2, st, mid, l, r) + sum(node * 2 + 1, mid + 1, en, l, r);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    init(1, 1, N);
    for (int i = 0; i < M + K; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if (a == 1) { // b번째 수를 c로 업데이트
            update(1, 1, N, b, c - num[b]);
            num[b] = c;
        }
        else { // b번째 수부터 c번째 수까지의 합
            cout << sum(1, 1, N, b, c) << '\n';
        }
    }
    return 0;
}