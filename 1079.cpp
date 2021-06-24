#include <bits/stdc++.h>
using namespace std;

int N;
int g[20];
int R[20][20];
int mafia;
int visited[20];
int mx;

// cnt: 남은 사람 수, night_cnt: 지나간 밤 수
void dfs(int cnt, int night_cnt) {
    if (cnt == 1 || visited[mafia] == 1) { // 마피아 혼자 남았거나 마피아가 죽었을 경우에 게임 종료
        mx = max(mx, night_cnt);
    }
    else if (cnt % 2 == 0) { // 밤이라면 마피아가 죽일 사람을 고른다
        for (int i = 0; i < N; i++) {
            if (visited[i] || i == mafia) continue;

            visited[i] = 1; // i번째 사람을 죽인다.
            for (int j = 0; j < N; j++)
                g[j] += R[i][j];

            dfs(cnt - 1, night_cnt + 1);

            // backtracking
            visited[i] = 0;
            for (int j = 0; j < N; j++)
                g[j] -= R[i][j];
        }
    }
    else { // 낮이라면
        int most_guilty;
        int max_guilty = -0x7f7f;
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (g[i] > max_guilty) {
                max_guilty = g[i];
                most_guilty = i;
            }
        }
        visited[most_guilty] = 1; // 유죄 지수가 가장 높은 사람을 죽인다.
        dfs(cnt - 1, night_cnt);
        visited[most_guilty] = 0; // backtracking
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> R[i][j];
        }
    }
    cin >> mafia;
    dfs(N, 0);
    cout << mx;
    return 0;
}