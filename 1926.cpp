#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define X       first
#define Y       second
using namespace std;

int n, m;
int field[505][505];
int visited[505][505];
int cnt, mx;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int x, int y) {
    queue<PAIR> q;
    PAIR cur;
    int nx, ny;
    int sz = 1;
    visited[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = cur.X + dx[i];
            ny = cur.Y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 1 && visited[nx][ny] == 0) {
                sz++;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return sz;
}

void foo() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 1 && visited[i][j] == 0) {
                cnt++;
                mx = max(mx, bfs(i, j));
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> field[i][j];
    }
    foo();
    cout << cnt << "\n" << mx; 
    return 0;
}