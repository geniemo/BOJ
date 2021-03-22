#include <bits/stdc++.h>
#define PAIR pair<ll, int>
#define SUM first
#define MIN_IDX second
using namespace std;

using ll = long long;

int N;
ll arr[100001] = {0x7fffffff};
PAIR tree[100001 * 4]; // 구간의 합, 최소와 최소의 인덱스를 저장

PAIR init(int node, int st, int en) {
    if (st == en)
        return tree[node] = {arr[st], st};
    int mid = (st + en) / 2;
    PAIR left = init(node * 2, st, mid);
    PAIR right = init(node * 2 + 1, mid + 1, en);
    return tree[node] = {left.SUM + right.SUM, (arr[left.MIN_IDX] < arr[right.MIN_IDX]) ? left.MIN_IDX : right.MIN_IDX};
}

PAIR getSumAndMinIdx(int node, int st, int en, int l, int r) {
    if (en < l || r < st)
        return {0, 0};
    if (l <= st && en <= r)
        return {tree[node].SUM, tree[node].MIN_IDX};
    int mid = (st + en) / 2;
    PAIR left = getSumAndMinIdx(node * 2, st, mid, l, r);
    PAIR right = getSumAndMinIdx(node * 2 + 1, mid + 1, en, l, r);
    return {left.SUM + right.SUM, (arr[left.MIN_IDX] < arr[right.MIN_IDX]) ? left.MIN_IDX : right.MIN_IDX};
}

ll getMax(int l, int r) {
    if (l == r)
        return arr[l] * arr[l];
    PAIR cur = getSumAndMinIdx(1, 1, N, l, r);
    ll mx = cur.SUM * arr[cur.MIN_IDX];
    if (cur.MIN_IDX - 1 >= l)
        mx = max(mx, getMax(l, cur.MIN_IDX - 1));
    if (cur.MIN_IDX + 1 <= r)
        mx = max(mx, getMax(cur.MIN_IDX + 1, r));
    return mx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    init(1, 1, N);
    cout << getMax(1, N);
    return 0;
}