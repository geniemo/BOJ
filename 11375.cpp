#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> edges[1005];
int b[1005];
int visited[1005];

bool dfs(int idx) {
    if (visited[idx]) return false;
    visited[idx] = 1;
    for (int i : edges[idx]) {
        if (b[i] == -1 || dfs(b[i])) {
            b[i] = idx;
            return true;
        }
    }
    return false;
}

int b_match() {
    memset(b, -1, sizeof(b));
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) cnt++;
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int t, w;
        cin >> t;
        while (t--) {
            cin >> w;
            edges[i].push_back(w);
        }
    }
    cout << b_match();
    return 0;
}