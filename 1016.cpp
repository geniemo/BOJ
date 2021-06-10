#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mn, mx;
int sieve[1'100'005];
int nn_sieve[1'100'005];
int res;

void init() {
    for (ll i = 2; i <= 1'100'000; i++) {
        if (sieve[i])
            continue;
        for (ll j = i * i; j <= 1'100'000; j += i)
            sieve[j]++;
    }
}

void nn_num() {
    for (ll i = 2; i <= 1'100'000; i++) {
        // 소수가 아닌 수의 제곱수에 대해선 생각할 필요가 없으므로 continue
        if (sieve[i])
            continue;
        ll cur = i * i;
        for (ll j = (mn / cur) * cur; j <= mx; j += cur) {
            // 음수 인덱싱을 방지
            if (j - mn >= 0)
                nn_sieve[j - mn]++;
        }
    }
    for (ll i = 0; i <= mx - mn; i++) {
        if (nn_sieve[i] == 0)
            res++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init(); // 110만까지의 소수를 다 찾는다
    cin >> mn >> mx;
    nn_num();
    cout << res;
    return 0;
}