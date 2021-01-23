#include <iostream>
using namespace std;

int N;
int map[100][100];
long long dp[100][100];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    dp[0][0] = 1;
    for (int curX = 0; curX < N; curX++)
    {
        for (int curY = 0; curY < N; curY++)
        {
            int curD = map[curX][curY];
            if (curX < curX + curD && curX + curD < N)  
                dp[curX + curD][curY] += dp[curX][curY];
            if (curY < curY + curD && curY + curD < N)
                dp[curX][curY + curD] += dp[curX][curY];
        }
    }
    cout << dp[N - 1][N - 1];
    return 0;
}