#include <bits/stdc++.h>
using namespace std;

int st[100001];
int team[100001]; // 0: not yet visited, 1: visited, 2: have a team

void dfs(int id) {
    if (st[id] == id) {
        team[id] = 2;
        return;
    }
    unordered_set<int> hst;
    int cur = id;
    hst.insert(id);
    while (team[cur] == 0) {
        team[cur] = 1;
        cur = st[cur];
        // 앞서 나왔던 것이 다시 나왔으므로 loop 발견
        if (hst.find(cur) != hst.end()) {
            // loop를 형성하는 학생들을 group으로 만든다.
            int tmp = cur;
            team[tmp] = 2;
            while (st[tmp] != cur) {
                tmp = st[tmp];
                team[tmp] = 2;
            }
            break;
        }
        hst.insert(cur);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int T_ = 0; T_ < T; T_++) {
        int n;
        cin >> n;
        fill(team, team + n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> st[i];
        for (int i = 1; i <= n; i++) {
            if (team[i] == 0)
                dfs(i);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (team[i] != 2)
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}