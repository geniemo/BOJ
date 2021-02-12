#include <iostream>
using namespace std;

int M, N;
int sieve[1000001] = {1, 1, }; // 1은 소수가 아니므로

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i] == 0) {
            for (long long j = i * static_cast<long long>(i); j <= 1000000; j += i)
                sieve[j]++;
        }
    }
    cin >> M >> N;
    for (int i = M; i <= N; i++) {
        if (sieve[i] == 0)
            cout << i << '\n';
    }
    return 0;
}