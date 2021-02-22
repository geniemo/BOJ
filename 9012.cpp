#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string paren;
        cin >> paren;
        stack<char> s;
        bool is_VPS = true;
        for (char p : paren) {
            if (p == '(')
                s.push(p);
            else {
                if (s.empty() || s.top() != '(') {
                    is_VPS = false;
                    break;
                }
                s.pop();
            }
        }
        cout << (is_VPS && s.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}