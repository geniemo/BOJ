#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define A       first
#define B       second
using namespace std;

int N, M;
PAIR edges[1005]; // i번째 사람은 A이상 B이하의 책을 원한다.
int b[1005];
int visited[1005];

bool dfs(int idx) {
    if (visited[idx]) return false;
    visited[idx] = 1;
    for (int i = edges[idx].A; i <= edges[idx].B; i++) {
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
    for (int i = 0; i < M; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) cnt++;
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> edges[i].A >> edges[i].B;
        }
        cout << b_match() << "\n";
    }
    return 0;
}