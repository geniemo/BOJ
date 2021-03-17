#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long mul(int a, int b) {
    if (b == 1)
        return a % C;
    long long res = mul(a, b / 2) % C;
    if (b % 2 == 0)
        return res * res % C;
    return res * res % C * a % C;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B >> C;
    cout << mul(A, B);
    return 0;
}