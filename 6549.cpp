#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        int h[100005] = {0, };
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        long long mx = 0;
        stack<int> s_idx;
        s_idx.push(0);
        for (int i = 1; i <= n + 1; i++) {
            while (h[s_idx.top()] > h[i]) {
                int idx = s_idx.top();
                s_idx.pop();
                mx = max(mx, static_cast<long long>(h[idx]) * (i - s_idx.top() - 1));
            }
            s_idx.push(i);
        }
        cout << mx << '\n';
    }
    return 0;
}