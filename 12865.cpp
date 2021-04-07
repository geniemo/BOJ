#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define W       first
#define V       second
using namespace std;

int N, K;
PAIR stuff[105];
int dp[105][100005];
int mx;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> stuff[i].W >> stuff[i].V;
    //sort(stuff, stuff + N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (stuff[i].W <= j)
                dp[i][j] = max(dp[i - 1][j], stuff[i].V + dp[i - 1][j - stuff[i].W]);
            else
                dp[i][j] = dp[i - 1][j];
        }
        mx = max(mx, dp[i][K]);
    }
    cout << mx;
    return 0;
}