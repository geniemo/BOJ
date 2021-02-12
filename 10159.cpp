#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> heavy[101];
unordered_set<int> heavyDp[101];
vector<int> light[101];
unordered_set<int> lightDp[101];

// i번째 물건보다 무거운 것들을 heavpDp[i]에 저장
void heavy_dfs(int i) {
    if (heavy[i].empty() || !heavyDp[i].empty())
        return;
    for (int j : heavy[i]) {
        heavyDp[i].insert(j);
        heavy_dfs(j);
        heavyDp[i].insert(heavyDp[j].begin(), heavyDp[j].end());
    }
}
// i번째 물건보다 가벼운 것들을 lightDp[i]에 저장
void light_dfs(int i) {
    if (light[i].empty() || !lightDp[i].empty())
        return;
    for (int j : light[i]) {
        lightDp[i].insert(j);
        light_dfs(j);
        lightDp[i].insert(lightDp[j].begin(), lightDp[j].end());
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int h, l;
        cin >> h >> l;
        light[h].push_back(l); // h보다 가벼워야 하는 것들
        heavy[l].push_back(h); // l보다 무거워야 하는 것들
    }
    for (int i = 1; i <= N; i++) {
        heavy_dfs(i); light_dfs(i);
        cout << N - (heavyDp[i].size() + lightDp[i].size() + 1) << '\n';
    }
    return 0;
}