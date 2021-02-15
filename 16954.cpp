#include <bits/stdc++.h>
#define PAIR pair<int, int>
#define X first
#define Y second
using namespace std;

string maze[8];
vector<PAIR> wall; // 벽의 좌표를 기록
int dx[] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 0, 1};

// 벽 이동
void move() {
    vector<PAIR> nWall;
    for (PAIR pos : wall) {
        if (pos.X <= 7) {
            maze[pos.X][pos.Y] = '.';
            if (pos.X + 1 <= 7)
                nWall.push_back({pos.X + 1, pos.Y});
        }
    }
    for (PAIR pos : nWall)
        maze[pos.X][pos.Y] = '#';
    wall = nWall;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    for (int i = 0; i < 8; i++) {
        cin >> maze[i];
        for (int j = 0; j < 8; j++) {
            if (maze[i][j] == '#')
                wall.push_back({i, j});
        }
    }
    bool is_possible = false;
    queue<PAIR> q;
    q.push({7, 0});
    while (!q.empty() && !is_possible) {
        bool visit[8][8] = {0, };
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            PAIR cur = q.front(); q.pop();
            if (cur.X == 0 && cur.Y == 7) {
                is_possible = true;
                break;
            }
            if (maze[cur.X][cur.Y] == '#')
                continue;
            for (int j = 0; j < 9; j++) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];
                if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && maze[nx][ny] == '.' && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        move();
    }
    cout << (is_possible ? 1 : 0);
    return 0;
}