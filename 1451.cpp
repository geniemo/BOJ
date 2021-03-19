#include <bits/stdc++.h>
using namespace std;

int N, M;
int rec[101][101];
long long mx;

int getSum(int stX, int stY, int enX, int enY) {
    int sum = 0;
    for (int i = stX; i < enX; i++) {
        for (int j = stY; j < enY; j++)
            sum += rec[i][j];
    }
    return sum;
}

long long getMax() {
    long long s1, s2, s3;
    // 세로로 세개가 놓인 경우
    for (int i = 0; i < M - 2; i++) {
        for (int j = i + 1; j < M - 1; j++) {
            s1 = getSum(0, 0, N, i + 1);
            s2 = getSum(0, i + 1, N, j + 1);
            s3 = getSum(0, j + 1, N, M);
            mx = max(mx, s1 * s2 * s3);
        }
    }
    // 가로로 세개가 놓인 경우
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            s1 = getSum(0, 0, i + 1, M);
            s2 = getSum(i + 1, 0, j + 1, M);
            s3 = getSum(j + 1, 0, N, M);
            mx = max(mx, s1 * s2 * s3);
        }
    }
    // 왼쪽에 세로 하나 오른쪽에 가로 둘
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            s1 = getSum(0, 0, N, i + 1);
            s2 = getSum(0, i + 1, j + 1, M);
            s3 = getSum(j + 1, i + 1, N, M);
            mx = max(mx, s1 * s2 * s3);
        }
    }
    // 왼쪽에 가로 둘 오른쪽에 세로 하나
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            s1 = getSum(0, 0, j + 1, i + 1);
            s2 = getSum(j + 1, 0, N, i + 1);
            s3 = getSum(0, i + 1, N, M);
            mx = max(mx, s1 * s2 * s3);
        }
    }
    // 위에 가로 하나 아래에 세로 둘
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            s1 = getSum(0, 0, i + 1, M);
            s2 = getSum(i + 1, 0, N, j + 1);
            s3 = getSum(i + 1, j + 1, N, M);
            mx = max(mx, s1 * s2 * s3);
        }
    }
    // 위에 세로 둘 아래에 가로 하나
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            s1 = getSum(0, 0, i + 1, j + 1);
            s2 = getSum(0, j + 1, i + 1, M);
            s3 = getSum(i + 1, 0, N, M);
            mx = max(mx, s1 * s2 * s3);
        }
    }
    return mx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++)
            rec[i][j] = tmp[j] - '0';
    }
    cout << getMax();
    return 0;
}