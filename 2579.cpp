#include <iostream>
#include <algorithm>
using namespace std;

int n;
int stair[301];
int dp[301];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stair[i];

    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    for (int i = 3; i <= n; i++)
        dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + dp[i - 3] + stair[i]);
    cout << dp[n];
    return 0;
}