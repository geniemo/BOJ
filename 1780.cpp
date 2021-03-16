#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2200][2200];
int cnt[3];

bool isComplete(int x, int y, int sz) {
    for (int i = x; i < x + sz; i++) {
        for (int j = y; j < y + sz; j++) {
            if (paper[i][j] != paper[x][y])
                return false;
        }
    }
    return true;
} 

void cut(int x, int y, int sz) {
    if (isComplete(x, y, sz)) {
        cnt[paper[x][y] + 1]++;
        return;
    }
    int newSz = sz / 3;
    for (int i = x; i < x + sz; i += newSz) {
        for (int j = y; j < y + sz; j += newSz) {
            cut(i, j, newSz);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    }
    cut(0, 0, N);
    for (int i = 0; i < 3; i++)
        cout << cnt[i] << '\n';
    return 0;
}