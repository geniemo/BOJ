#include <bits/stdc++.h>
using namespace std;

int N;
int b[55];
int cnt[55];

void sol() {
    for (int i = 1; i <= N; i++) {
        double mx_incl = -0x7f7f7f7f;
        for (int j = i + 1; j <= N; j++) {
            double incl = (b[j] - b[i]) / (double)(j - i);
            if (incl > mx_incl) {
                mx_incl = incl;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }
    sol();
    cout << *max_element(cnt, cnt + 55);
    return 0;
}