#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define X       first
#define Y       second
using namespace std;

int N, M;
string maze[105];
int depth[105][105];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs() {
    queue<PAIR> q;
    PAIR cur;
    int nx, ny;
    depth[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = cur.X + dx[i];
            ny = cur.Y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] == '1' && depth[nx][ny] == 0) {
                depth[nx][ny] = depth[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> maze[i];
    bfs();
    cout << depth[N - 1][M - 1];
    return 0;
}