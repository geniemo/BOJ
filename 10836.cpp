#include <bits/stdc++.h>
using namespace std;

int M, N;
int g[3];
int boundary[1500];

// 애벌레는 그 날 자신의 왼쪽, 왼쪽 위, 위가 모두 자란 뒤 자라는데
// 왼쪽 아래에서 오른쪽 위로 갈수록 그 날 애벌레가 자라는 수치가 커지므로
// 어떤 열의 애벌레는 그 열의 가장 윗 행의 애벌레가 자라는 만큼 자란다.
void grow() {
    for (int i = g[0]; i < 2 * M - 1; i++) {
        if (g[1]-- > 0)
            boundary[i] += 1;
        else {
            g[2]--;
            boundary[i] += 2;
        }
    }
}

void print() {
    for (int i = M - 1; i >= 0; i--) {
        cout << boundary[i] << " ";
        for (int j = 0; j < M - 1; j++)
            cout << boundary[M + j] << " ";
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    fill(boundary, boundary + 1500, 1);
    for (int N_ = 0; N_ < N; N_++) {
        cin >> g[0] >> g[1] >> g[2];
        grow();
    }
    print();
    return 0;
}