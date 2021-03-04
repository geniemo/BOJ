#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> v;
int res;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());
    int l = v[0].first, r = v[0].second;
    for (auto p : v) {
        // 겹치는 경우에(포함되는 경우는 무시한다.)
        if (p.first <= r && r < p.second) {
            r = p.second; // 오른쪽을 갱신
        }
        // 전혀 겹치지 않는 경우에
        else if (r < p.first) {
            res += r - l; // 여태까지의 길이를 더하고
            l = p.first; // 왼쪽, 오른쪽을 갱신
            r = p.second;
        }
    }
    res += r - l;
    cout << res;
    return 0;
}