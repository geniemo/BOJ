#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[1000][1000];
int dp[1000][1000];
int Right[1000]; // 오른쪽으로
int Left[1000]; // 왼쪽으로

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    dp[0][0] = map[0][0];
    for (int i = 1; i < M; i++)
        dp[0][i] = dp[0][i - 1] + map[0][i]; 
    for (int i = 1; i < N; i++)
    {
        Right[0] = dp[i - 1][0] + map[i][0];
        for (int j = 1; j < M; j++)
            Right[j] = max(Right[j - 1] + map[i][j], dp[i - 1][j] + map[i][j]); // 왼쪽에서 온 경로와 위에서 온 경로 중 최댓값

        Left[M - 1] = dp[i - 1][M - 1] + map[i][M - 1];
        for (int j = M - 2; j >= 0; j--)
            Left[j] = max(Left[j + 1] + map[i][j], dp[i - 1][j] + map[i][j]); // 오른쪽에서 온 경로와 위에서 온 경로 중 최댓값

        for (int j = 0; j < M; j++)
            dp[i][j] = max(Right[j], Left[j]);
    }
    cout << dp[N - 1][M - 1];
    return 0;
}