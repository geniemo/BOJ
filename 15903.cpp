#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void play() {
    ll n1 = pq.top();
    pq.pop();
    ll n2 = pq.top();
    pq.pop();
    pq.push(n1 + n2);
    pq.push(n1 + n2);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    ll tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }
    for (int i = 0; i < m; i++)
        play();

    ll res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res;
    return 0;
}