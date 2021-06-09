#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define X       first
#define Y       second
using namespace std;

int T;
int N;
PAIR d[25];
int visited[25];
double res;

double len() {
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            x += d[i].X;
            y += d[i].Y;
        }
        else {
            x -= d[i].X;
            y -= d[i].Y;
        }
    }
    return sqrt((double)x * x + (double)y * y);
}

void dfs(int cnt, int idx) {
    if (cnt == N / 2) {
        res = min(res, len());
        return;
    }
    if (idx == N)
        return;
    dfs(cnt, idx + 1);
    visited[idx] = 1;
    dfs(cnt + 1, idx + 1);
    visited[idx] = 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(15);

    cin >> T;
    while (T--) {
        res = 0x7fffffffffffffff;
        memset(visited, 0, sizeof(visited));
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> d[i].X >> d[i].Y;
        }
        dfs(0, 0);
        cout << res << "\n";
    }
    return 0;
}