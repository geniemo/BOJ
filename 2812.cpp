#include <bits/stdc++.h>
using namespace std;

int N, K;
string num;
string res = "";

void maxNum() {
    for (auto c : num) {
        while (K > 0 && !res.empty() && res.back() < c) {
            res.pop_back();
            K--;
        }
        res += c;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    cin >> num;
    maxNum();
    cout << res.substr(0, res.length() - K);
    return 0;
}