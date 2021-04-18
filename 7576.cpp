#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define X       first
#define Y       second
using namespace std;

int M, N;
int field[1005][1005];
int dist[1005][1005];
queue<PAIR> apple_q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오 왼 아 위

void bfs() {
    PAIR cur;
    int nx, ny;
    while (!apple_q.empty()) {
        cur = apple_q.front();
        apple_q.pop();
        for (int i = 0; i < 4; i++) {
            nx = cur.X + dx[i];
            ny = cur.Y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && dist[nx][ny] < 0) {
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                apple_q.push({nx, ny});
            }
        }
    }
}

int getCnt() {
    int mx = 0; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1)
                return -1;
        }
        mx = max(mx, *max_element(dist[i], dist[i] + M));
    }
    return mx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            if (field[i][j] == 1)
                apple_q.push({i, j});
            else if (field[i][j] == 0)
                dist[i][j] = -1;
        }
    }
    bfs();
    cout << getCnt();
    return 0;
}