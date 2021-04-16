#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define W       first
#define N       second
using namespace std;

int n, v1, v2, w;
vector<PAIR> edge[10005];
int dist[10005];

void dijkstra(int st) {
    memset(dist, -1, sizeof(dist));
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
    PAIR cur;
    int nDist;
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        if (dist[cur.N] < cur.W)
            continue;
        for (auto next : edge[cur.N]) {
            nDist = cur.W + next.W;
            if (dist[next.N] == -1 || nDist < dist[next.N]) {
                dist[next.N] = nDist;
                pq.push({nDist, next.N});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2 >> w;
        edge[v1].push_back({w, v2});
        edge[v2].push_back({w, v1});
    }
    dijkstra(1);
    int far_from_root = max_element(dist, dist + n + 1) - dist;
    dijkstra(far_from_root);
    cout << *max_element(dist, dist + n + 1);
    return 0;
}