#include <bits/stdc++.h>
#define PQ      priority_queue<PAIR, vector<PAIR>, greater<PAIR>>
#define PAIR    pair<int, int>
#define W       first
#define X       second
using namespace std;

int N, M;
int a, b, t;
vector<PAIR> edge[5005];
int parent[1005];
int dist[1005];

// 아무것도 막지 않았을 때의 최단경로를 기록
void path() {
    fill(dist, dist + 1005, 0x7f7f7f7);
    PQ pq;
    PAIR cur;
    int nDist;
    dist[1] = 0;
    parent[1] = 1;
    pq.push({0, 1});
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        if (dist[cur.X] < cur.W)
            continue;
        for (auto next : edge[cur.X]) {
            nDist = cur.W + next.W;
            if (nDist < dist[next.X]) {
                dist[next.X] = nDist;
                parent[next.X] = cur.X;
                pq.push({nDist, next.X});
            }
        }
    }
}

// block과 parent[block] 사이의 도로를 막았을 때의 시간
void dijkstra(int block) {
    fill(dist, dist + 1005, 0x7f7f7f7);
    PQ pq;
    PAIR cur;
    int nDist;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        if (dist[cur.X] < cur.W)
            continue;
        for (auto next : edge[cur.X]) {
            nDist = cur.W + next.W;
            if (nDist < dist[next.X] && !((cur.X == block && next.X == parent[block]) || (cur.X == parent[block] && next.X == block))) {
                dist[next.X] = nDist;
                pq.push({nDist, next.X});
            }
        }
    }
}

// 최단경로상의 경로를 막지 않는다면 최단경로를 이용하면 되므로 지연시간은 0
// 따라서, 최단경로의 도로를 하나씩 막으면서 확인
int getMaxDelay() {
    int fastest = dist[N];
    int mx = -1;
    int tmp = N;
    while (tmp != 1) {
        dijkstra(tmp);
        if (dist[N] == 0x7f7f7f7) // 탈출 못하도록 막는 방법이 있다면 -1
            return -1;
        mx = max(mx, dist[N] - fastest);
        tmp = parent[tmp];
    }
    return mx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> t;
        edge[a].push_back({t, b});
        edge[b].push_back({t, a});
    }
    path();
    cout << getMaxDelay();
    return 0;
}