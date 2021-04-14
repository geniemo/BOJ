#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define W       first
#define X       second
using namespace std;

int T;
int n, d, c;
int a, b, s;
vector<PAIR> edge[10005];
int dist[10005];

void init() {
    for (int i = 0; i < 10005; i++)
        edge[i].clear();
    fill(dist, dist + 10005, 0x7f7f7f7f);
}

void dijkstra(int st) {
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
    PAIR cur;
    int nDist;
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        if (dist[cur.X] < cur.W)
            continue;
        for (auto next : edge[cur.X]) {
            nDist = cur.W + next.W;
            if (nDist < dist[next.X]) {
                dist[next.X] = nDist;
                pq.push({nDist, next.X});
            }
        }
    }
}

void sol() {
    int cnt = 0, t = -1;
    dijkstra(c);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x7f7f7f7f)
            continue;
        cnt++;
        t = max(t, dist[i]);
    }
    cout << cnt << " " << t << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int T_ = 0; T_ < T; T_++) {
        init();
        cin >> n >> d >> c;
        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            edge[b].push_back({s, a});
        }
        sol();
    }
    return 0;
}