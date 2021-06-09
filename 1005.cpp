#include <bits/stdc++.h>
using namespace std;

int T;
int N, K; // 건물 개수, 건물건설규칙 개수
int d[1005]; // 건물당 건설에 걸리는 시간
int X, Y; // 건설순서, X 지은 후 Y 지을 수 있다.
int W; // 승리하기 위해 건설해야 할 건물의 번호

vector<int> edges[1005];
int degree[1005]; // 더 먼저 건설되어야 하는 건물의 수

int res[1005];

void init() {
    for (int i = 0; i < 1005; i++)
        edges[i].clear();
    memset(degree, 0, sizeof(degree));
    memset(res, 0, sizeof(res));
}

void sol() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        // 바로 건설할 수 있으면 push
        if (degree[i] == 0) {
            q.push(i);
            res[i] = d[i];
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i : edges[cur]) {
            if (--degree[i] == 0) // i를 짓기 위한 조건을 모두 충족햇다면
                q.push(i);
            res[i] = max(res[i], res[cur] + d[i]);
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
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            edges[X].push_back(Y);
            degree[Y]++;
        }
        cin >> W;
        sol();
        cout << res[W] << "\n";
    }
    return 0;
}