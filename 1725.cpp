#include <bits/stdc++.h>
using namespace std;

int N;
int h[100005];
int mx;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> h[i];
    stack<int> s_idx;
    s_idx.push(0);
    for (int i = 1; i <= N + 1; i++) {
        while (!s_idx.empty() && h[s_idx.top()] > h[i]) {
            int idx = s_idx.top();
            s_idx.pop();
            mx = max(mx, h[idx] * (i - s_idx.top() - 1));
        }
        s_idx.push(i);
    }    
    cout << mx;
    return 0;
}