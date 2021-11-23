/*
BOJ 16953: A -> B
*/

#include <bits/stdc++.h>
using namespace std;

int a, b;
int ans = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        ans++;
        int sz = q.size();
        while (sz--) {
            int cur = q.front(); q.pop();
            int next1 = cur * 2, next2 = cur * 10 + 1;
            if (next1 == b || next2 == b) {
                cout << ans + 1;
                return 0;         
            }

            if (0 < next1 && next1 <= b / 2) q.push(next1);
            if (0 < next2 && next2 <= b / 2) q.push(next2);
        }
    }
    cout << -1;
    return 0;
}