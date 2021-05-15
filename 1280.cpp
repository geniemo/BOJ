#include <bits/stdc++.h>
#define PAIR    pair<ll, ll>
#define CNT     first
#define SUM     second
using namespace std;

using ll = long long;
const int mod = 1'000'000'007;

int N;
int pos;
ll sum;
PAIR tree[200'005 * 4];
ll res = 1;

void update(int node, int st, int en, int pos) {
    if (pos < st || en < pos)
        return;
    tree[node].SUM += pos;
    tree[node].CNT += 1;
    if (st == en)
        return;
    int mid = (st + en) / 2;
    update(node * 2, st, mid, pos);
    update(node * 2 + 1, mid + 1, en, pos);
}

PAIR left(int node, int st, int en, int pos) {
    if (pos < st)
        return {0, 0};
    if (en <= pos)
        return tree[node];
    int mid = (st + en) / 2;
    PAIR l = left(node * 2, st, mid, pos);
    PAIR r = left(node * 2 + 1, mid + 1, en, pos);
    return {l.CNT + r.CNT, l.SUM + r.SUM};
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> pos;
    sum += pos;
    update(1, 0, 200000, pos);
    for (int i = 1; i < N; i++) {
        cin >> pos;
        PAIR l = left(1, 0, 200000, pos);
        PAIR r = {i - l.CNT, sum - l.SUM};
        res *= (((l.CNT * pos - l.SUM) % mod) + (abs(r.CNT * pos - r.SUM) % mod)) % mod;
        res %= mod;
        sum += pos;
        update(1, 0, 200000, pos);
    }
    cout << res;
    return 0;
}