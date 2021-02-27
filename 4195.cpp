#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> cnt; // root가 key인 트리의 노드 수

string find(string x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(string x, string y) {
    x = find(x), y = find(y);
    // 이미 같은 트리에 있으므로 함수 종료
    if (x == y) return;
    // 노드가 더 적은 트리를 큰 트리에 연결
    if (cnt[x] > cnt[y]) swap(x, y);
    parent[x] = y;
    cnt[y] += cnt[x];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        parent.clear();
        cnt.clear();
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            string x, y;
            cin >> x >> y;
            // x 또는 y가 새로 등장한 친구라면 초기값 설정
            if (parent.find(x) == parent.end()) {
                parent[x] = x;
                cnt[x] = 1;
            }
            if (parent.find(y) == parent.end()) {
                parent[y] = y;
                cnt[y] = 1;
            }
            merge(x, y);
            cout << cnt[find(x)] << '\n';
        }
    }
    return 0;
}