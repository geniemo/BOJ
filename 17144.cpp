#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define X       first
#define Y       second
using namespace std;

int R, C, T;
int room[55][55];
int tmp[55][55];
PAIR cleaner_u;
PAIR cleaner_d;
queue<PAIR> dustQ;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void spread() {
    memcpy(tmp, room, sizeof(tmp));
    PAIR cur;
    int cnt;
    int nx, ny;
    while (!dustQ.empty()) {
        cur = dustQ.front();
        dustQ.pop();
        cnt = 0;
        for (int i = 0; i < 4; i++) {
            nx = cur.X + dx[i];
            ny = cur.Y + dy[i];
            if (1 <= nx && nx <= R && 1 <= ny && ny <= C && tmp[nx][ny] != -1) {
                room[nx][ny] += tmp[cur.X][cur.Y] / 5;
                cnt++;
            }
        }
        room[cur.X][cur.Y] -= (tmp[cur.X][cur.Y] / 5) * cnt;
    }
}

void clean() {
    int i;
    // 위쪽 공기청정기
    for (i = cleaner_u.X - 1; i >= 2; i--)
        room[i][1] = room[i - 1][1];
    for (i = 1; i <= C - 1; i++)
        room[1][i] = room[1][i + 1];
    for (i = 1; i <= cleaner_u.X - 1; i++)
        room[i][C] = room[i + 1][C];
    for (i = C; i >= 3; i--)
        room[cleaner_u.X][i] = room[cleaner_u.X][i - 1];
    room[cleaner_u.X][2] = 0;
    // 아래쪽 공기청정기
    for (i = cleaner_d.X + 1; i <= R - 1; i++)
        room[i][1] = room[i + 1][1];
    for (i = 1; i <= C - 1; i++)
        room[R][i] = room[R][i + 1];
    for (i = R; i >= cleaner_d.X + 1; i--)
        room[i][C] = room[i - 1][C];
    for (i = C; i >= 3; i--)
        room[cleaner_d.X][i] = room[cleaner_d.X][i - 1];
    room[cleaner_d.X][2] = 0;
}

int getSum() {
    int sum = 0;
    PAIR cur;
    while (!dustQ.empty()) {
        cur = dustQ.front();
        dustQ.pop();
        sum += room[cur.X][cur.Y];
    }
    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> T;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) { // 공기청정기
                if (cleaner_u.first == 0)
                    cleaner_u = {i, j};
                else
                    cleaner_d = {i, j};
            }
            else if (room[i][j] != 0) { // 먼지
                dustQ.push({i, j});
            }
        }
    }
    for (int t = 0; t < T; t++) {
        spread();
        clean();
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (room[i][j] > 0)
                    dustQ.push({i, j});
            }
        }
    }
    cout << getSum();
    return 0;
}