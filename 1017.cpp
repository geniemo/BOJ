#include <bits/stdc++.h>
using namespace std;

int N;
int arr[55];
int b[55];
vector<int> edges[55];
int visited[55];
vector<int> res;

int sieve[2005] = {1, 1, };

void init() {
    for (int i = 2; i <= 2000; i++) {
        if (sieve[i]) continue;
        for (int j = i * i; j <= 2000; j += i)
            sieve[j] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (sieve[arr[i] + arr[j]] == 0)
                edges[i].push_back(j);
        }
    }
}

bool dfs(int idx) {
    if (visited[idx]) return false;
    visited[idx] = 1;
    for (int i : edges[idx]) {
        // 아직 i번째 수가 짝을 짓지 않았거나 짝을 지은 수가 다른 수를 고를 수 있다면
        if (b[i] == -1 || dfs(b[i])) {
            b[i] = idx;
            return true;
        }
    }
    return false;
}

int b_match() {
    memset(b, -1, sizeof(b));
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        // 첫 번째 수와 다른 그룹이라면 dfs를 하지 않는다
        if (arr[i] % 2 != arr[0] % 2) continue;
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) cnt++;
    }
    // N / 2 개의 쌍이 만들어졌다면
    if (cnt == N / 2) {
        return find(b, b + N, 0) - b; // 첫 번째 숫자와 짝을 지은 수의 인덱스 반환
    }
    return 0;
}

void sol() {
    while (1) {
        int match_with_1st = b_match();
        if (match_with_1st) {
            res.push_back(arr[match_with_1st]);
            // 이후의 이분매칭에서는 방금 res에 반영한 match_with_1st는 고려하지 않도록 한다
            edges[0].erase(find(edges[0].begin(), edges[0].end(), match_with_1st));
            edges[match_with_1st].erase(find(edges[match_with_1st].begin(), edges[match_with_1st].end(), 0));
        }
        else
            break;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init();
    sol();
    if (res.empty())
        cout << -1;
    else {
        sort(res.begin(), res.end());
        for (int i : res)
            cout << i << " ";
    }
    return 0;
}