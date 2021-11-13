#include <bits/stdc++.h>
using namespace std;

int n;
int x;
map<int, int> m;
int cnt;

void sol() {
    for (auto e : m) {
        int target = x - e.first;
        if (m[e.first] == 2 || target <= 0 || target == e.first || m.find(x - e.first) == m.end()) continue;
        m[e.first] = m[x - e.first] = 2;
        cnt++;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        m[num] = 1;
    }
    cin >> x;
    sol();
    cout << cnt;
    return 0;
}