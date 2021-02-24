#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int T_ = 0; T_ < T; T_++) {
        int N;
        cin >> N;
        int res = 0;
        int pos[1001];
        int dst[1001];
        for (int i = 1; i <= N; i++) {
            pos[i] = i;
            cin >> dst[i];
        }
        for (int i = 1; i <= N; i++) {
            int idx = find(pos, pos + N + 1, dst[i]) - pos;
            for (int j = idx; j > i; j--) {
                swap(pos[j], pos[j - 1]);
                res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}