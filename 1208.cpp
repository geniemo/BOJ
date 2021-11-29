#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[45];
unordered_map<int, int> m;
long long res;

void l() {
    queue<int> q;
    q.push(0);
    for (int i = 0; i < n / 2; i++) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front(); q.pop();
            q.push(cur);
            q.push(cur + arr[i]);
        }
    }
    while (!q.empty()) {
        m[q.front()]++;
        q.pop();
    }
}

void r() {
    queue<int> q;
    q.push(0);
    for (int i = n / 2; i < n; i++) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front(); q.pop();
            q.push(cur);
            q.push(cur + arr[i]);
        }
    }
    while (!q.empty()) {
        res += m[s - q.front()];
        q.pop();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    l(); r();
    if (s == 0) res--;
    cout << res;
    return 0;
}