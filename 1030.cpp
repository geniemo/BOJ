#include <bits/stdc++.h>
using namespace std;

int s, n, k, r1, r2, c1, c2;
int lu, rd;

void print(int sz, int r, int c) {
    if ((lu <= (r / sz) % n && (r / sz) % n <= rd) && (lu <= (c / sz) % n && (c / sz) % n <= rd))
        cout << 1;
    else if (sz / n == 0)
        cout << 0;
    else
        print(sz / n, r, c);
}

void sol() {
    int sz = pow(n, s);
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            print(sz, i, j);
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    lu = (n - k) / 2;
    rd = (n - 1) - lu;
    sol();
    return 0;
}