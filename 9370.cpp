#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define D       first
#define N       second
using namespace std;

int T; // 테스트 케이스 수
int n, m, t; // 교차로, 도로, 목적지 후보 개수
int s, g, h; // 예술가들 출발지, 예술가들은 g와 h 거쳐감
int a, b, d; // a와 b사이에 길이 d의 양방향 도로
int x[105]; // t개의 목적지 후보들
vector<PAIR> edge[2005];
int distS[2005];
int distG[2005];
int distH[2005];

void init() {
    for (int i = 0; i < 2005; i++)
        edge[i].clear();
    fill(distS, distS + 2005, 0x7f7f7f7f);
    fill(distG, distG + 2005, 0x7f7f7f7f);
    fill(distH, distH + 2005, 0x7f7f7f7f);
    memset(x, 0, sizeof(x));
}

void dijkstra(int st, int dist[]) {
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> q;
    PAIR cur;
    int nDist;
    dist[st] = 0;
    q.push({dist[st], st});
    while (!q.empty()) {
        cur = q.top();
        q.pop();
        if (dist[cur.N] < cur.D)
            continue;
        for (auto next : edge[cur.N]) {
            nDist = cur.D + next.D;
            if (nDist < dist[next.N]) {
                dist[next.N] = nDist;
                q.push({nDist, next.N});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        init();
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        while (m--) {
            cin >> a >> b >> d;
            edge[a].push_back({d, b});
            edge[b].push_back({d, a});
        }
        for (int i = 0; i < t; i++)
            cin >> x[i];
        sort(x, x + t);
        dijkstra(s, distS);
        dijkstra(g, distG);
        dijkstra(h, distH);
        for (int i = 0; i < t; i++) {
            if (distS[x[i]] == distS[g] + distG[h] + distH[x[i]] || distS[x[i]] == distS[h] + distH[g] + distG[x[i]])
                cout << x[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}