#include <bits/stdc++.h>
using namespace std;

int N;
int field[16][16];
int cnt;

bool isValid(int x, int y) {
    for (int i = 0; i < N; i++) {
        if (field[x][i] == 1 || field[i][y] == 1)
            return false;
    }
    int nx = x, ny = y;
    while (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (field[nx][ny] == 1)
            return false;
        nx--; ny--;
    }
    nx = x, ny = y;
    while (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (field[nx][ny] == 1)
            return false;
        nx++; ny--;
    }
    return true;
}

void dfs(int depth) {
    if (depth == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (field[i][depth] == 1 || !isValid(i, depth))
            continue;
        field[i][depth] = 1;
        dfs(depth + 1);
        field[i][depth] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    dfs(0);
    cout << cnt;
    return 0;
}