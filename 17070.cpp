#include <bits/stdc++.h>
#define ti3 tuple<int, int, int>
#define X get<0>
#define Y get<1>
#define DIR get<2>
using namespace std;

enum {HOR, VER, RD}; // 수평, 수직, 오른쪽 아래

int N;
int home[17][17];
int cnt;
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1}; // 아래, 오른, 대각

bool IsInBound(ti3 pipe) {
    return 1 <= X(pipe) && X(pipe) <= N && 1 <= Y(pipe) && Y(pipe) <= N;
}

bool IsSafe(ti3 pipe) {
    switch (DIR(pipe)) {
        case HOR: case VER:
            return home[X(pipe)][Y(pipe)] == 0;
        case RD:
            return home[X(pipe)][Y(pipe)] == 0 && home[X(pipe) - 1][Y(pipe)] == 0 && home[X(pipe)][Y(pipe) - 1] == 0;
    }
    return false;
}

void DFS() {
    stack<ti3> s;
    s.push(make_tuple(1, 2, HOR));
    while (!s.empty()) {
        ti3 cur = s.top();
        s.pop();
        if (X(cur) == N && Y(cur) == N) {
            cnt++;
            continue;
        }
        // 가로로 놓여있다면 오른쪽 이동과 대각선 이동
        // 세로로 놓여있다면 아래 이동과 대각선 이동
        // 대각선으로 놓여있다면 아래, 오른쪽, 대각선 이동
        for (int i = 0; i < 3; i++) {
            if (DIR(cur) == i && DIR(cur) != RD)
                continue;
            int ndir = (i == 0) ? VER : (i == 1) ? HOR : RD;
            ti3 next = make_tuple(X(cur) + dx[i], Y(cur) + dy[i], ndir);
            if (IsInBound(next) && IsSafe(next))
                s.push(next);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> home[i][j];
    }
    DFS();
    cout << cnt;
    return 0;
}