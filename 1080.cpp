#include <bits/stdc++.h>
using namespace std;

int N, M;
string A[50];
string B[50];
bool is_diff[50][50];
int cnt;

void conv33(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++)
            is_diff[i][j] = !is_diff[i][j];
    }
}

bool isPossible() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (is_diff[i][j])
                return false;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            is_diff[i][j] = (A[i][j] != B[i][j]);
        }
    }
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (is_diff[i][j]) {
                conv33(i, j);
                cnt++;
            }
        }
    }
    cout << (isPossible() ? cnt : -1);
    return 0;
}