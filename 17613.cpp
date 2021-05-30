#include <bits/stdc++.h>
using namespace std;

int T;
int x, y;
map<pair<int, int>, int> dp; // k: {l, r}, v: j

int j(int l, int r) {
    if (l == 0 && r == 0)
        return 0;
    if (dp.find({l, r}) != dp.end())
        return dp[{l, r}];
    int res = 0;
    // 2 ^ 30 > 10 ^ 9
    for (int i = 1; i <= 29; i++) {
        int jl = max(l, (1 << i) - 1); // 재시작 없이 i번 점프 -> 2 ^ i - 1
        int jr = min(r, (1 << (i + 1)) - 2); // 재시작 없이 i + 1번 점프 - 1 -> 2 ^ (i + 1) - 2

        // 재시작 후 다음번에 점프해야할 구간
        int nl = jl - ((1 << i) - 1);
        int nr = jr - ((1 << i) - 1);

        if (jl <= jr) res = max(res, j(nl, nr) + i);
    }
    return dp[{l, r}] = res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> x >> y;
        cout << j(x, y) << "\n";
    }
    return 0;
}