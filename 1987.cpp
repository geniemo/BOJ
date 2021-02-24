#include <bits/stdc++.h>
using namespace std;

int R, C;
char field[20][20];
int alpha_visit['Z' - 'A' + 1];
int visit[20][20];
int cnt;
int mx;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오 왼 아 위

void dfs(int x, int y) {
    alpha_visit[field[x][y] - 'A'] = 1;
    visit[x][y] = 1;
    cnt++;
    mx = max(mx, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < R && 0 <= ny && ny < C && alpha_visit[field[nx][ny] - 'A'] == 0 && visit[nx][ny] == 0)
            dfs(nx, ny);
    }
    alpha_visit[field[x][y] - 'A'] = 0;
    visit[x][y] = 0;
    cnt--;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> field[i][j];
    }
    dfs(0, 0);
    cout << mx;
    return 0;
}