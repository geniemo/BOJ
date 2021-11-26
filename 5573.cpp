/*
BOJ 5573: 산책
*/

#include <bits/stdc++.h>
using namespace std;

int H, W, N;
int mat[1005][1005];
int dp[1005][1005]; // 각 칸에 들리는 횟수

void cnt() {
    dp[1][1] = N - 1; // N - 1 번째 산책을 마친 후에는 첫 칸에 들리는 횟수
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (mat[i][j] == 1) { // 원래 오른 쪽으로 가야 하는 칸이면
                dp[i][j + 1] += dp[i][j] / 2 + dp[i][j] % 2;
                dp[i + 1][j] += dp[i][j] / 2;
            }
            else { // 왼쪽으로 가야 하는 칸이면
                dp[i][j + 1] += dp[i][j] / 2;
                dp[i + 1][j] += dp[i][j] / 2 + dp[i][j] % 2;
            }
        }
    }
}

// cnt에서 세었을 때 짝수번 들린 칸이면 방향이 안바뀌고, 홀수번 들린 칸이면 방향이 바뀐다.
void update() {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            mat[i][j] = dp[i][j] % 2 == 0 ? mat[i][j] : !mat[i][j];
        }
    }
}

void walk(int x, int y) {
    if (x > H || y > W) {
        cout << x << " " << y;
        return;
    }
    if (mat[x][y] == 0) walk(x + 1, y);
    else walk(x, y + 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W >> N;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> mat[i][j];
        }
    }
    cnt();
    update();
    walk(1, 1);
    return 0;
}