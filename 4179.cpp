#include <bits/stdc++.h>
#define PAIR pair<int, int>
#define X first
#define Y second
using namespace std;

int R, C;
string maze[1005];
int depth[1005][1005];
queue<PAIR> fire;
PAIR initialPos;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오 왼 아 위

void fireEx() {
    int nx, ny;
    int sz = fire.size();
    PAIR cur;
    for (int i = 0; i < sz; i++) {
        cur = fire.front();
        fire.pop();
        for (int j = 0; j < 4; j++) {
            nx = cur.X + dx[j];
            ny = cur.Y + dy[j];
            if (0 <= nx && nx < R && 0 <= ny && ny < C && maze[nx][ny] == '.') {
                maze[nx][ny] = 'F';
                fire.push({nx, ny});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> maze[i];
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'F')
                fire.push({i, j});
            else if (maze[i][j] == 'J') {
                maze[i][j] = '.';
                initialPos = {i, j};
            }
        }
    }

    queue<PAIR> q;
    depth[initialPos.X][initialPos.Y] = 1;
    q.push(initialPos);
    PAIR cur;
    int nx, ny;
    int sz;
    while (!q.empty()) {
        fireEx();
        sz = q.size();
        for (int i = 0; i < sz; i++) {
            cur = q.front();
            q.pop();
            if (cur.X == 0 || cur.X == R - 1 || cur.Y == 0 || cur.Y == C - 1) {
                cout << depth[cur.X][cur.Y];
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                nx = cur.X + dx[i];
                ny = cur.Y + dy[i];
                if (0 <= nx && nx < R && 0 <= ny && ny < C && maze[nx][ny] == '.' && depth[nx][ny] == 0) {
                    depth[nx][ny] = depth[cur.X][cur.Y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}