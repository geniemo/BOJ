#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int depth[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> F >> S >> G >> U >> D;
    queue<int> q;
    depth[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == G) 
            break;
        int nxtU = cur + U;
        int nxtD = cur - D;
        if (1 <= nxtU && nxtU <= F && depth[nxtU] == 0) {
            depth[nxtU] = depth[cur] + 1;
            q.push(nxtU);
        }
        if (1 <= nxtD && nxtD <= F && depth[nxtD] == 0) {
            depth[nxtD] = depth[cur] + 1;
            q.push(nxtD);
        }
    }
    if (depth[G] != 0)
        cout << depth[G] - 1;
    else
        cout << "use the stairs";
    return 0;
}