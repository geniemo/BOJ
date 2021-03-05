#include <bits/stdc++.h>
using namespace std;

enum {EAST = 1, WEST, NORTH, SOUTH};

int N, M;
int x, y;
int K;
int board[20][20];
vector<int> dice(6);

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0}; // 동, 서, 북, 남

void move(int dir) {
    switch (dir) {
    case EAST:
        dice = {dice[1], dice[3], dice[2], dice[4], dice[0], dice[5]};
        break;
    case WEST:
        dice = {dice[4], dice[0], dice[2], dice[1], dice[3], dice[5]};
        break;
    case NORTH:
        dice = {dice[5], dice[1], dice[0], dice[2], dice[4], dice[3]};
        break;
    case SOUTH:
        dice = {dice[2], dice[1], dice[3], dice[5], dice[4], dice[0]};
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < K; i++) {
        int dir;
        cin >> dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!(0 <= nx && nx < N && 0 <= ny && ny < M))
            continue;
        move(dir);
        if (board[nx][ny] == 0)
            board[nx][ny] = dice[3];
        else {
            dice[3] = board[nx][ny];
            board[nx][ny] = 0;
        }
        cout << dice[0] << '\n'; // 윗면 출력
        x = nx, y = ny;
    }
    return 0;
}