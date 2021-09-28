#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define W       first
#define N       second
using namespace std;

int n, m, x;
vector<PAIR> edges[1005];
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
int dist[1005][1005];
int parent[1005];
int visited[1005];

void init() {
    for (int i = 0; i < 1005; i++) {
        fill(dist, dist + 1005, 0x7f7f7f7f);
    }
}

void r_dijkstra() {
    pq.push({0, x}); // 시작점
    dist[x][x] = 0;
    while (!pq.empty()) {
        PAIR cur = pq.top();
        pq.pop();
        if (dist[x][cur.N] <= cur.W) continue;

        for (auto next : edges[cur.N]) {
            int ndist = cur.W + next.W;
            if (ndist < dist[x][next.N]) {
                dist[x][next.N] = ndist;
                pq.push({ndist, next.N});
            }
        }
    }
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        pq.push({0, i});
        while (!pq.empty()) {
            PAIR cur = pq.top();
            pq.pop();
            if (dist[i][cur.N] <= cur.W) continue;
            if (cur.N == x) {

            }

            for (auto next : edges[cur.N]) {
                int ndist = cur.W + next.W;
                if (ndist < dist[x][next.N]) {
                    parent[next.N] = cur.N;
                    dist[cur.N][next.N] = ndist;
                    pq.push({ndist, next.N});
                }
            }
        }
    }
}

int sol() {
    init();
    r_dijkstra(); // 돌아갈 때의 시간을 계산

    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int src, dst, w;
        cin >> src >> dst >> w;
        edges[src].push_back({w, dst});
    }
    cout << sol();
    return 0;
}