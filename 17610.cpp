#include <bits/stdc++.h>
using namespace std;

int k;
int g[15];
int s;
int dp[15][3000000];

void sol(int cur, int idx) {
    if (idx > k)
        return;
    dp[idx][cur] = 1;
    sol(cur, idx + 1);
    sol(cur + g[idx], idx + 1);
    sol(abs(cur - g[idx]), idx + 1);
}

int getCnt() {
    int cnt = 0;
    for (int i = 1; i <= s; i++) {
        if (dp[k][i] == 0)
            cnt++;
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> g[i];
        s += g[i];
    }
    sol(0, 0);
    cout << getCnt();
    return 0;
}