#include <bits/stdc++.h>
using namespace std;

int N;
string word[10];
vector<int> v;
map<char, int> m;
int mx;

void setPriority() {
    int len;
    int digits;
    for (int i = 0; i < N; i++) {
        len = word[i].length();
        digits = 1;
        for (int j = len - 1; j >= 0; j--) {
            m[word[i][j]] += digits;
            digits *= 10;
        }
    }
    for (auto p : m)
        v.push_back(p.second);
    sort(v.begin(), v.end(), greater<int>());
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word[i];
        for (char c : word[i]) {
            if (m.find(c) == m.end())
                m.insert({c, 0});
        }
    }
    setPriority();
    int tmp = 9;
    for (int i : v)
        mx += i * tmp--;
    cout << mx;
    return 0;
}