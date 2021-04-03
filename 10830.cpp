#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll N, B;
ll org[5][5];
ll res[5][5];
ll tmp[5][5];

void mulMat(ll a[][5], ll b[][5]) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++)
                tmp[i][j] += a[i][k] * b[k][j];
            tmp[i][j] %= 1000;
        }
    }
    memcpy(a, tmp, sizeof(tmp));
}

void powMat(ll E) {
    while (E > 0) {
        if (E % 2 == 1)
            mulMat(res, org);
        mulMat(org, org);
        E /= 2;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> org[i][j];
        }
        res[i][i] = 1; // res는 단위행렬
    }
    powMat(B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << res[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}