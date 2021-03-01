#include <bits/stdc++.h>
using namespace std;

int N, K;
int depth[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    fill(depth, depth + 100001, 0x7fffffff);
    queue<int> q;
    depth[N] = 1;
    q.push(N);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == K)
            break;
        int t = cur * 2;
        while (t <= 100000 && depth[cur] < depth[t]) {
            depth[t] = depth[cur];
            q.push(t);
            t *= 2;
        }
        int l = cur - 1, r = cur + 1;
        if (0 <= l && depth[cur] + 1 < depth[l]) {
            depth[l] = depth[cur] + 1;
            q.push(l);
        }
        if (r <= 100000 && depth[cur] + 1 < depth[r]) {
            depth[r] = depth[cur] + 1;
            q.push(r);
        }
    }
    cout << depth[K] - 1;
    return 0;
}