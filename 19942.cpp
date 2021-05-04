#include <bits/stdc++.h>
#define ti5     tuple<int, int, int, int, int>
#define p       get<0>
#define f       get<1>
#define s       get<2>
#define v       get<3>
#define c       get<4>
using namespace std;

int N;
ti5 mn;
ti5 food[20];
int visited[20];
int res = 0x7f7f7f7f;
int res_use[20];

void dfs(ti5 cur, int idx) {
    if (c(cur) >= res)
        return;
    if (p(cur) >= p(mn) && f(cur) >= f(mn) && s(cur) >= s(mn) && v(cur) >= v(mn) && c(cur) < res) {
        res = c(cur);
        memcpy(res_use, visited, sizeof(visited));
        return;
    }

    for (int i = idx; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs({p(cur) + p(food[i]), f(cur) + f(food[i]), s(cur) + s(food[i]), v(cur) + v(food[i]), c(cur) + c(food[i])}, i + 1);
        visited[i] = 0;
    }
}

void print() {
    if (res == 0x7f7f7f7f) {
        cout << -1;
        return;
    }
    cout << res << "\n";
    for (int i = 1; i <= N; i++) {
        if (res_use[i])
            cout << i << " ";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> p(mn) >> f(mn) >> s(mn) >> v(mn);
    for (int i = 1; i <= N; i++) {
        cin >> p(food[i]) >> f(food[i]) >> s(food[i]) >> v(food[i]) >> c(food[i]);
    }
    dfs({0, 0, 0, 0, 0}, 1);
    print();
    return 0;
}