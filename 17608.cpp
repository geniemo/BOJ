#include <bits/stdc++.h>
using namespace std;

int N;
int h[100005];
int mx;
int cnt;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> h[i];
    for (int i = N - 1; i >= 0; i--) {
        if (h[i] > mx) {
            mx = h[i];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}