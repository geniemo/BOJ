#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[5001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    fill(dp, dp + 5001, 5001);
    dp[0] = 0;
    for (int i = 0; i <= N - 3; i++)
    {
        if (dp[i] + 1 < dp[i + 3])
            dp[i + 3] = dp[i] + 1;
        if (dp[i] + 1 < dp[i + 5])
            dp[i + 5] = dp[i] + 1;
    }
    if (dp[N] == 5001)
        cout << -1;
    else
        cout << dp[N];
    return 0;
}