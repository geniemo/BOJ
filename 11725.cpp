/*
BOJ 11725: 트리의 부모 찾기
*/

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> child[100005];
int parent[100005];
int visited[100005];
int a, b;

void dfs(int cur) {
    visited[cur] = 1;

    for (int i : child[cur]) {
        if (visited[i]) continue;
        parent[i] = cur;
        dfs(i);
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}