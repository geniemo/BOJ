#include <bits/stdc++.h>
using namespace std;

int N, K;
int depth[100001];
int before[100001];

void bfs() {
    fill(before, before + 100001, -1);
    queue<int> q;
    depth[N] = 1;
    before[N] = N;
    q.push(N);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == K)
            return;
        int t = cur * 2;
        int l = cur - 1;
        int r = cur + 1;
        if (t <= 100000 && depth[t] == 0) {
            depth[t] = depth[cur] + 1;
            before[t] = cur;
            q.push(t);
        }
        if (l >= 0 && depth[l] == 0) {
            depth[l] = depth[cur] + 1;
            before[l] = cur;
            q.push(l);
        }
        if (r <= 100000 && depth[r] == 0) {
            depth[r] = depth[cur] + 1;
            before[r] = cur;
            q.push(r);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    bfs();
    cout << depth[K] - 1 << '\n';
    vector<int> path;
    int tmp = K;
    while (tmp != N) {
        path.push_back(tmp);
        tmp = before[tmp];
    }
    path.push_back(tmp);
    reverse(path.begin(), path.end());
    for (int i : path)
        cout << i << ' ';
    return 0;
}