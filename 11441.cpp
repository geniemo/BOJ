#include <bits/stdc++.h>
using namespace std;

int N, M;
int acc[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int n;
    for (int i = 1; i <= N; i++) {
        cin >> n;
        acc[i] = acc[i - 1] + n;
    }

    cin >> M;
    int l, r;
    for (int i = 0; i < M; i++) {
        cin >> l >> r;
        cout << acc[r] - acc[l - 1] << '\n';
    }
    return 0;
}