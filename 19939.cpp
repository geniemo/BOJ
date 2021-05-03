#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    N -= K * (K + 1) / 2;
    if (N < 0)
        cout << -1;
    else if (N % K == 0)
        cout << K - 1;
    else
        cout << K;
    return 0;
}