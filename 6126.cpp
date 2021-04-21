#include <bits/stdc++.h>
using namespace std;

int V, N; // kinds of coin, goal
int coin;
long long dp[10'005] = {1, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> N;
    for (int i = 0; i < V; i++) {
        cin >> coin;
        for (int j = 0; j <= N - coin; j++) {
            dp[j + coin] += dp[j];
        }
    }
    cout << dp[N];
    return 0;
}