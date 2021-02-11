#include <bits/stdc++.h>
#define PAIR pair<int, int>
#define X first
#define Y second
using namespace std;

int N, M;
int m[1001][1001];
int fromSt[1001][1001];
int fromEn[1001][1001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오 왼 아 위

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= M; j++)
            m[i][j] = tmp[j - 1] - '0';
    }

    queue<PAIR> q;
    // 출발점으로부터의 거리를 계산
    fromSt[1][1] = 1;
    q.push({1, 1});
    while (!q.empty()) {
        PAIR cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && m[nx][ny] == 0 && fromSt[nx][ny] == 0) {
                fromSt[nx][ny] = fromSt[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
    // 도착점으로부터의 거리를 계산
    fromEn[N][M] = 1;
    q.push({N, M});
    while (!q.empty()) {
        PAIR cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && m[nx][ny] == 0 && fromEn[nx][ny] == 0) {
                fromEn[nx][ny] = fromEn[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
    // 시작점부터 도착점까지 벽을 부수지 않고 갈 수 있다면 그 거리로 값을 할당
    int mn = (fromEn[1][1] == 0) ? 0x7fffff : fromEn[1][1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // 벽과 인접한 네 칸 중에 시작점에서 가장 가까운 지점의 fromSt + 도착점에서 가장 가까운 지점의 fromEn + 1이 해당 벽을 부수고 가는 거리
            if (m[i][j] == 1) {
                int minFromSt = 0x7fffff, minFromEn = 0x7fffff;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (1 <= nx && nx <= N && 1 <= ny && ny <= M && m[nx][ny] == 0) {
                        if (fromSt[nx][ny] > 0) // nx ny로 시작점에서 갈 수 있는 방법이 있다면
                            minFromSt = min(minFromSt, fromSt[nx][ny]);
                        if (fromEn[nx][ny] > 0) // 그리고 도착점에서 갈 수 있는 방법이 있다면
                            minFromEn = min(minFromEn, fromEn[nx][ny]);
                    }
                }
                mn = min(mn, minFromSt + 1 + minFromEn);
            }
        }
    }
    cout << (mn == 0x7fffff ? -1 : mn);
    return 0;
}