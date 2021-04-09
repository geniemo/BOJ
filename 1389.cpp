#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int A, B;
int mat[105][105];

void floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

int who() {
    int min = 0x7f7f7f7f;
    int kevin;
    int sum;
    for (int i = 1; i <= N; i++) {
        sum = 0;
        for (int j = 1; j <= N; j++) {
            if (mat[i][j] == 0x7f7f7f)
                continue;
            sum += mat[i][j];
        }
        if (sum < min) {
            min = sum;
            kevin = i;
        }
    }
    return kevin;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < 105; i++) {
        fill(mat[i], mat[i] + 105, 0x7f7f7f);
        mat[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        mat[A][B] = mat[B][A] = 1;
    }
    floyd();
    cout << who();
    return 0;
}