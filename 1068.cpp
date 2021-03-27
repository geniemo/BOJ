#include <bits/stdc++.h>
using namespace std;

int N;
int root;
int parent[55];
vector<int> sibling[55];
int del;

int getLeafCnt() {
    int cnt = 0;
    queue<int> q;
    int cur;
    q.push(root);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (sibling[cur].empty()) {
            cnt++;
            continue;
        }
        for (auto& s : sibling[cur])
            q.push(s);
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> parent[i];
        if (parent[i] == -1)
            root = i;
        else
            sibling[parent[i]].push_back(i);
    }
    cin >> del;
    if (del == root) {
        cout << 0;
        return 0;
    }
    // del 노드 지우기
    sibling[parent[del]].erase(find(sibling[parent[del]].begin(), sibling[parent[del]].end(), del));
    cout << getLeafCnt();
    return 0;
}