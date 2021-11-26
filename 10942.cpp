#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[2005];
int dp[2005][2005];

void sol() {
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int l = 2; l <= n; l++) {
        for (int st = 0; st < n - l + 1; st++) {
            int en = st + l - 1;
            if (arr[st] != arr[en]) continue;
            dp[st][en] = l == 2 || dp[st + 1][en - 1];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sol();
    cin >> m;
    while (m--) {
        int st, en;
        cin >> st >> en;
        cout << dp[st - 1][en - 1] << "\n";
    }
    return 0;
}