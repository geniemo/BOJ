#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define X       first
#define Y       second
using namespace std;

int N;
string field[105];
int visited[105][105];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int getNormalCnt() {
    int cnt = 0;
    queue<PAIR> q;
    PAIR cur;
    int nx, ny;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1)
                continue;
            cnt++;
            visited[i][j] = 1;
            q.push({i, j});
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    nx = cur.X + dx[k];
                    ny = cur.Y + dy[k];
                    if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[nx][ny] == 0 && field[nx][ny] == field[cur.X][cur.Y]) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return cnt;
}

int getBlindCnt() {
    for (int i = 0; i < N; i++)
        fill(visited[i], visited[i] + N, 0);
    int cnt = 0;
    queue<PAIR> q;
    PAIR cur;
    int nx, ny;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1)
                continue;
            cnt++;
            visited[i][j] = 1;
            q.push({i, j});
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    nx = cur.X + dx[k];
                    ny = cur.Y + dy[k];
                    if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[nx][ny] == 0) {
                        if (field[cur.X][cur.Y] == 'B') {
                            if (field[cur.X][cur.Y] == field[nx][ny]) {
                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                        else {
                            if (field[nx][ny] != 'B') {
                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> field[i];
    cout << getNormalCnt() << " " << getBlindCnt();
    return 0;
}