#include <bits/stdc++.h>
#define PI2 pair<int, int>
#define PI3 pair<pair<int, int>, int>
#define LOC first
#define X first
#define Y second
#define ST first
#define EN second
#define DIR second
#define DIST second
using namespace std;

int N, M;
int field[10][10];
int islCnt;
int parent[7] = {0, 1, 2, 3, 4, 5, 6};
int depth[7];
int res;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오 왼 아 위

// 각 섬에 번호를 붙인다.
void setID() {
    queue<PI2> q;
    int id = 1;
    int visit[10][10] = {0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j] == 0 && field[i][j] == 1) {
                visit[i][j] = 1;
                field[i][j] = id;
                q.push({i, j});
                while (!q.empty()) {
                    PI2 cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (0 <= nx && nx < N && 0 <= ny && ny < M && visit[nx][ny] == 0 && field[nx][ny] == 1) {
                            visit[nx][ny] = 1;
                            field[nx][ny] = id;
                            q.push({nx, ny});
                        }
                    }
                }
                id++;
            }
        }
    }
    // 섬의 수를 기록
    islCnt = id - 1;
}

// 다리의 후보를 생성하고 다리들을 길이의 오름차순으로 정렬, union-find 를 이용한 Kruskal algorithm을 이용해 다리 생성
int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]); // 경로의 모든 노드들의 부모 노드를 루트 노드로 설정
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    // 이미 같은 트리에 속하는 것이므로 함수 종료
    if (x == y) return;
    // 높이가 더 낮은 트리를 더 높은 트리에 붙인다
    if (depth[x] > depth[y])
        swap(x, y);
    parent[x] = y;
    if (depth[x] == depth[y])
        depth[x]++;
}
bool isCycle(int st, int en) {
    st = find(st);
    en = find(en);
    if (st == en)
        return true;
    return false;
}
bool cmp(PI3& a, PI3& b) {
    return a.DIST < b.DIST;
}
void makeBridge() {
    vector<PI3> bridge;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] != 0) {
                stack<PI3> s;
                // 현재 위치에서 네 방향으로 탐색
                s.push({{i, j}, 0});
                s.push({{i, j}, 1});
                s.push({{i, j}, 2});
                s.push({{i, j}, 3});
                while (!s.empty()) {
                    PI3 cur = s.top();
                    s.pop();
                    // 다른 섬에 도달했다면 bridge 정보를 저장
                    if (1 <= field[cur.LOC.X][cur.LOC.Y] && field[cur.LOC.X][cur.LOC.Y] <= 6 && field[cur.LOC.X][cur.LOC.Y] != field[i][j]) {
                        int dist = abs((i - cur.LOC.X) + (j - cur.LOC.Y)) - 1; // 다리의 길이
                        if (dist > 1) // 다리의 길이는 1보다 길어야 한다.
                            bridge.push_back({{field[i][j], field[cur.LOC.X][cur.LOC.Y]}, dist});
                        continue;
                    }
                    // 같은 방향으로만 진행
                    int nx = cur.LOC.X + dx[cur.DIR];
                    int ny = cur.LOC.Y + dy[cur.DIR];
                    // 지금과 같은 섬이 아닌 다른 곳으로 나아간다면 push
                    if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] != field[i][j])
                        s.push({{nx, ny}, cur.DIR});
                }
            }
        }
    }
    // Kruskal algorithm, 다리의 후보를 길이의 오름차순으로 정렬
    sort(bridge.begin(), bridge.end(), cmp);
    for (auto cur : bridge) {
        // 사이클이 아니라면 연결
        if (!isCycle(cur.LOC.ST, cur.LOC.EN)) {
            res += cur.DIST;
            merge(cur.LOC.ST, cur.LOC.EN);
        }
    }
}

// 모든 섬들이 서로 연결되었는지 확인(union find를 사용)
bool isConnected() {
    int root = find(1);
    for (int i = 2; i <= islCnt; i++) {
        if (root != find(i))
            return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> field[i][j];
    }
    setID(); // 각 섬들의 ID를 지정
    makeBridge(); // 다리를 만들어준다.
    cout << (isConnected() ? res : -1); // 만들어준 다리로 모두 다 연결됐다면 다리의 길이의 합을, 연결되지 못했다면 -1을 출력
    return 0;
}