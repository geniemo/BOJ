/*
BOJ 1202: 보석 도둑
*/

#include <bits/stdc++.h>
#define V   first
#define W   second
using namespace std;

int n, k;
priority_queue<pair<int, int>> pq;
map<int, int> m;
int w, v;
int c;
long long res;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        pq.push({v, w}); // 비쌀수록 top에
    }
    while (k--) {
        cin >> c;
        m[c]++;
    }
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        auto it = m.lower_bound(cur.W);
        if (it == m.end()) continue;
        res += cur.V;
        if (--it->second == 0) {
            m.erase(it);
        }
    }
    cout << res;
    return 0;
}