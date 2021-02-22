#include <bits/stdc++.h>
#define PAIR pair<int, int>
#define X first
#define Y second
using namespace std;

int N, M, fuel;
int road[21][21];
int depth[21][21];
map<PAIR, PAIR> customer;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오 왼 아 위

struct cmp {
    bool operator()(PAIR& a, PAIR& b) {
        if (depth[b.X][b.Y] != depth[a.X][a.Y])
            return depth[b.X][b.Y] < depth[a.X][a.Y];
        if (b.X != a.X) return b.X < a.X;
        return b.Y < a.Y;
    }
};

// 최적의 위치에 있는 손님의 위치를 반환
PAIR findCustomer(PAIR st) {
    for (int i = 1; i <= N; i++)
        fill(depth[i] + 1, depth[i] + N + 1, -1);
    priority_queue<PAIR, vector<PAIR>, cmp> pq;
    depth[st.X][st.Y] = 0;
    pq.push(st);
    while (!pq.empty()) {
        PAIR cur = pq.top();
        pq.pop();
        if (customer.find(cur) != customer.end())
            return cur;
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N && road[nx][ny] == 0 && depth[nx][ny] == -1) {
                depth[nx][ny] = depth[cur.X][cur.Y] + 1;
                pq.push({nx, ny});
            }
        }
    }
    return {-1, -1};
}
// 손님의 목적지까지의 거리를 반환
int distToDst(PAIR st, PAIR dst) {
    for (int i = 1; i <= N; i++)
        fill(depth[i] + 1, depth[i] + N + 1, -1);
    queue<PAIR> q;
    depth[st.X][st.Y] = 0;
    q.push({st.X, st.Y});
    while (!q.empty()) {
        PAIR cur = q.front();
        q.pop();
        if (cur == dst)
            return depth[cur.X][cur.Y];
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N && road[nx][ny] == 0 && depth[nx][ny] == -1) {
                depth[nx][ny] = depth[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return 0x7fffff;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> fuel;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> road[i][j];
    }
    PAIR st;
    cin >> st.X >> st.Y;
    for (int i = 0; i < M; i++) {
        PAIR st, dst;
        cin >> st.X >> st.Y >> dst.X >> dst.Y;
        customer[st] = dst;
    }
    while (!customer.empty()) {
        PAIR cust = findCustomer(st);
        int dist1 = depth[cust.X][cust.Y]; // 손님까지의 거리
        int dist2 = distToDst(cust, customer[cust]); // 손님의 목적지까지의 거리
        if (dist1 + dist2 > fuel)
            break;
        fuel -= dist1 + dist2;
        fuel += dist2 * 2;
        st = customer[cust];
        customer.erase(cust);
    }
    if (customer.empty())
        cout << fuel;
    else
        cout << -1;
    return 0;
}