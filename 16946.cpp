#include <bits/stdc++.h>
#define PAIR pair<int, int>
#define X first
#define Y second
using namespace std;

int N, M;
int wMap[1000][1000];
int res[1000][1000];
int visit[1000][1000];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오 왼 아 위

void bfs(int i, int j) {
    set<PAIR> wall;
    int cnt = 0;
    queue<PAIR> q;
    visit[i][j] = 1;
    q.push({i, j});
    while (!q.empty()) {
        PAIR cur = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (wMap[nx][ny] == 0 && visit[nx][ny] == 0) {
                    visit[nx][ny] = 1;
                    q.push({nx, ny});
                }
                else if (wMap[nx][ny] == 1)
                    wall.insert({nx, ny});
            }
        }
    }
    for (auto w : wall)
        res[w.X][w.Y] = (res[w.X][w.Y] + cnt) % 10;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++)
            res[i][j] = wMap[i][j] = tmp[j] - '0';
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (wMap[i][j] == 0 && visit[i][j] == 0)
                bfs(i, j);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << res[i][j];
        cout << '\n';
    }
    return 0;
}