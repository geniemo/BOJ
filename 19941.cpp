#include <bits/stdc++.h>
using namespace std;

int N, K;
string str;
int cnt;

int left_bound(int pos) {
    int res = pos - K;
    return (res >= 0 ? res : 0);
}

int right_bound(int pos) {
    int res = pos + K;
    return (res < N ? res : N - 1);
}

void sol() {
    for (int i = 0; i < N; i++) {
        if (str[i] != 'P')
            continue;
        for (int j = left_bound(i); j <= right_bound(i); j++) {
            if (str[j] == 'H') {
                str[j] = '.';
                cnt++;
                break;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    cin >> str;
    sol();
    cout << cnt;
    return 0;
}