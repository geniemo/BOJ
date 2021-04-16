#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define W       first
#define N       second
using namespace std;

int V;
int st, en, w;
vector<PAIR> edge[100005];
int dist[100005];

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

    cin >> V;
    for (int i = 0; i < V; i++) {
        cin >> st;
        while (1) {
            cin >> en;
            if (en == -1)
                break;
            cin >> w;
            edge[st].push_back({w, en});
        }
    }
    dijkstra(1);
    int far_from_1 = max_element(dist, dist + V + 1) - dist;
    dijkstra(far_from_1);
    cout << *max_element(dist, dist + V + 1);
    return 0;
}