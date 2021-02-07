#include <iostream>
#include <utility>
#include <algorithm>
#define T first
#define P second
using namespace std;

int N;
pair<int, int> counsel[15];
int dp[16];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> counsel[i].T >> counsel[i].P;
    for (int i = N - 1; i >= 0; i--)
    {
        if (i + counsel[i].T > N)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(counsel[i].P + dp[i + counsel[i].T], dp[i + 1]);
    }
    cout << dp[0];
    return 0;
}