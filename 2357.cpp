#include <bits/stdc++.h>
#define PAIR pair<ll, ll>
#define MIN first
#define MAX second
using namespace std;

using ll = long long;

int N, M;
ll arr[100001];
PAIR tree[100001 * 4];

PAIR init(int node, int st, int en) {
    if (st == en)
        return tree[node] = {arr[st], arr[st]};
    int mid = (st + en) / 2;
    PAIR left = init(node * 2, st, mid);
    PAIR right = init(node * 2 + 1, mid + 1, en);
    return tree[node] = {min(left.MIN, right.MIN), max(left.MAX, right.MAX)};
}

PAIR getMinMax(int node, int st, int en, int l, int r) {
    if (en < l || r < st)
        return {0x7f7f7f7f, 0};
    if (l <= st && en <= r)
        return tree[node];
    int mid = (st + en) / 2;
    PAIR left = getMinMax(node * 2, st, mid, l, r);
    PAIR right = getMinMax(node * 2 + 1, mid + 1, en, l, r);
    return {min(left.MIN, right.MIN), max(left.MAX, right.MAX)};
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    init(1, 1, N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        PAIR minMax = getMinMax(1, 1, N, a, b);
        cout << minMax.MIN << ' ' << minMax.MAX << '\n';
    }
    return 0;
}