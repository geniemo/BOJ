#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> edge[32001];
int degree[32001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int pre, post;
        cin >> pre >> post;
        edge[pre].push_back(post);
        degree[post]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        cout << cur << ' ';
        for (int i : edge[cur]) {
            degree[i]--;
            if (degree[i] == 0)
                q.push(i);
        }
    }
    return 0;
}