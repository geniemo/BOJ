#include <bits/stdc++.h>
using namespace std;

int N, K;
int sieve[1001] = {1, 1, };
int del[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= 1000; i++) {
        if (sieve[i] == 0) {
            for (int j = i * i; j <= 1000; j += i)
                sieve[j]++;
        }
    }
    cin >> N >> K;
    int res;
    while (K > 0) {
        int p = find(sieve, sieve + N + 1, 0) - sieve;
        sieve[p] = 1;
        for (int i = p; i <= N && K > 0; i += p) {
            if (del[i] == 0) {
                del[i] = 1;
                res = i;
                K--;
            }
        }
    }
    cout << res;
    return 0;
}