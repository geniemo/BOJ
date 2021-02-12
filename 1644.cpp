#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> prime;
int sieve[4000001];
int cnt;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (sieve[i] == 0) {
            prime.push_back(i);
            for (long long j = i * static_cast<long long>(i); j <= N; j += i)
                sieve[j]++;
        }
    }
    for (int i = 0; i < prime.size(); i++) {
        int sum = 0;
        for (int j = i; j < prime.size() && sum < N; j++)
            sum += prime[j];
        cnt = (sum == N) ? cnt + 1 : cnt;
    }
    cout << cnt;
    return 0;
}