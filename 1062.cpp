#include <bits/stdc++.h>
using namespace std;

int N, K; // a n t i c 을 제외한 K - 5 개의 알파벳을 더 학습 가능
int word_bit[55];
int learned = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));
int mx;

int getCnt() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!(word_bit[i] & (~learned)))
            cnt++;
    }
    return cnt;
}

void dfs(int idx, int depth) {
    if (depth >= K) {
        mx = max(mx, getCnt());
        return;
    }
    // 순서를 신경쓰지 않기 위해 idx를 이용
    for (int i = idx; i < 26; i++) {
        if ((learned >> i) & 1)
            continue;
        learned |= 1 << i;
        dfs(i, depth + 1);
        learned &= ~(1 << i);
    }
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    string word;
    for (int i = 0; i < N; i++) {
        cin >> word;
        for (auto c : word)
            word_bit[i] |= 1 << (c - 'a');
    }
    K -= 5;
    if (K < 0) {
        cout << 0;
        return 0;
    }
    dfs(0, 0);
    cout << mx;
    return 0;
}