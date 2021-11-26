#include <bits/stdc++.h>
using namespace std;

int x;
int depth[1'000'005];
int parent[1'000'005];

void sol() {
    fill(depth, depth + 1'000'005, 0x7f7f7f7f);
    queue<int> q;
    int cur, next;
    depth[x] = 0;
    q.push(x);
    while (!q.empty()) {
        cur = q.front(); q.pop();
        if (cur == 1) break;
        if (cur % 3 == 0) {
            next = cur / 3;
            if (depth[cur] + 1 < depth[next]) {
                depth[next] = depth[cur] + 1;
                parent[next] = cur;
                q.push(next);
            }
        }
        if (cur % 2 == 0) {
            next = cur / 2;
            if (depth[cur] + 1 < depth[next]) {
                depth[next] = depth[cur] + 1;
                parent[next] = cur;
                q.push(next);
            }
        }
        next = cur - 1;
        if (depth[cur] + 1 < depth[next]) {
            depth[next] = depth[cur] + 1;
            parent[next] = cur;
            q.push(next);
        }
    }
}

void print() {
    stack<int> s;
    int cur = 1;
    while (cur != x) {
        s.push(cur);
        cur = parent[cur];
    }
    s.push(x);
    cout << depth[1] << "\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> x;
    sol();
    print();
    return 0;
}