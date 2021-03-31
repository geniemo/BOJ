#include <bits/stdc++.h>
#define PAIR    pair<int, string>
#define NUM     first
#define OP      second
using namespace std;

int T, A, B;
int visited[10005];

int D(int a) {
    return a * 2 % 10000;
}
int S(int a) {
    if (a == 0)
        return 9999;
    return a - 1;
}
int L(int a) {
    return a % 1000 * 10 + a / 1000;
}
int R(int a) {
    return a % 10 * 1000 + a / 10;
}

void minCommand() {
    memset(visited, 0, sizeof(visited));
    queue<PAIR> q;
    PAIR cur;
    int nd, ns, nl, nr;
    visited[A] = 1;
    q.push({A, ""});
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.NUM == B) {
            cout << cur.OP << '\n';
            return;
        }
        nd = D(cur.NUM);
        if (visited[nd] == 0) {
            visited[nd] = 1;
            q.push({nd, cur.OP + 'D'});
        }
        ns = S(cur.NUM);
        if (visited[ns] == 0) {
            visited[ns] = 1;
            q.push({ns, cur.OP + 'S'});
        }
        nl = L(cur.NUM);
        if (visited[nl] == 0) {
            visited[nl] = 1;
            q.push({nl, cur.OP + 'L'});
        }
        nr = R(cur.NUM);
        if (visited[nr] == 0) {
            visited[nr] = 1;
            q.push({nr, cur.OP + 'R'});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int T_ = 0; T_ < T; T_++) {
        cin >> A >> B;
        minCommand();
    }
    return 0;
}