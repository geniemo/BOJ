#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int res[5];

void sol() {
    memset(res, 0, sizeof(res));
    res[0] += N / 60;
    N %= 60;
    if (N > 35) {
        res[0]++;
        res[2] += 6 - (N + 5) / 10;
        N %= 10;
        if (N >= 5) {
            res[4] += 10 - N;
        }
        else {
            res[3] += N;
        }
    }
    else {
        res[1] += (N + 4) / 10;
        N %= 10; 
        if (N >= 6) {
            res[4] += 10 - N;
        }
        else {
            res[3] += N;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        sol();
        for (int i = 0; i < 5; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    return 0;
}