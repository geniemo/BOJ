#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> edge[201]; // adjacency list
int dst[1000];
int visit[1001];

void bfs() {
    queue<int> q;
    visit[dst[0]] = 1;
    q.push(dst[0]);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : edge[cur]) {
            if (visit[i] == 0) {
                visit[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                edge[i].push_back(j);
        }
    }
    for (int i = 0; i < M; i++) 
        cin >> dst[i];
    bfs();
    bool is_possible = true;
    for (int i = 0; i < M; i++) {
        if (visit[dst[i]] == 0) {
            is_possible = false;
            break;
        }
    }
    cout << (is_possible ? "YES" : "NO");
    return 0;
}