/*
BOJ 1509: 팰린드롬 분할
*/

#include <bits/stdc++.h>
using namespace std;

string str;
int dp[2505][2505];
int depth[2505];

void sol1() {
    for (int i = 0; i < str.length(); i++) {
        dp[i][i] = 1;
    }
    for (int l = 2; l <= str.length(); l++) {
        for (int st = 0; st < str.length() - l + 1; st++) {
            int en = st + l - 1;
            if (str[st] != str[en]) continue;
            dp[st][en] = l == 2 || dp[st + 1][en - 1];
        }
    }
}

void sol2() {
    queue<int> q;
    depth[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur >= str.length()) {
            cout << depth[cur] - 1;
            return;
        }
        for (int i = cur; i < str.length(); i++) {
            if (dp[cur][i] == 0 || depth[i + 1]) continue;
            depth[i + 1] = depth[cur] + 1;
            q.push(i + 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;
    sol1();
    sol2();
    return 0;
}