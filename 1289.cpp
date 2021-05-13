#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define DST     first
#define W       second
using namespace std;

using ll = long long;
const ll mod = 1'000'000'007;

int N;
int a, b, w;
vector<PAIR> child[100'005];
ll res;

ll dfs(int cur, int parent) {
    ll sub = 1, acc;
    for (auto c : child[cur]) {
        if (c.DST == parent)
            continue;
        acc = dfs(c.DST, cur) * c.W % mod;
        res = (res + acc * sub) % mod;
        sub = (sub + acc) % mod;
    }
    return sub;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> w;
        child[a].push_back({b, w});
        child[b].push_back({a, w});
    }
    dfs(1, 0);
    cout << res;
    return 0;
}