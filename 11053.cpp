/*
BOJ 11053: 가장 긴 증가하는 부분 수열
*/

#include <bits/stdc++.h>
using namespace std;

int N;
int a[1005];
int dp[1005];

// 일반적이고 좋은 풀이
int lis1() {
    fill(dp, dp + 1005, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp, dp + N);
}

// 더 좋은 것 같진 않은데 값의 범위가 좁으니 이렇게도 풀 수 있지 않을까? 해서 풀어본 풀이
int lis2() {
    fill(dp, dp + 1005, 0);
    for (int i = 0; i < N; i++) {
        dp[a[i]] = *max_element(dp, dp + a[i]) + 1;
    }
    return *max_element(dp, dp + 1005);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << lis1();
    return 0;
}