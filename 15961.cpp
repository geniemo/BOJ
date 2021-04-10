#include <bits/stdc++.h>
using namespace std;

int N, d, k, c; // 초밥 접시수, 가짓수, 연속해서 먹는 접시수, 쿠폰번호
int sushi[3000005];
int cnt[3005];
int kind;

int getMax() {
    int mx = kind;
    int l = 0, r = k; // 0부터 r - 1까지 연속으로 먹는 경우
    while (r != k - 1) {
        if (--cnt[sushi[l]] == 0)
            kind--;
        if (++cnt[sushi[r]] == 1) {
            kind++;
            mx = max(mx, kind);
        }
        l = (l + 1) % N;
        r = (r + 1) % N;
    }
    return mx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> d >> k >> c;
    cnt[c] = 1;
    kind = 1;
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
        if (i < k) {
            cnt[sushi[i]]++;
            if (cnt[sushi[i]] == 1)
                kind++;
        }
    }
    cout << getMax();
    return 0;
}