#include <bits/stdc++.h>
using namespace std;

string paren;
int tmp = 1;
int res;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> paren;
    bool valid = paren[0] == '(' || paren[0] == '[';
    stack<char> s;
    for (int i = 0; i < paren.length() && valid; i++) {
        switch (paren[i]) {
        case '(':
            tmp *= 2;
            s.push(paren[i]);
            break;
        case '[':
            tmp *= 3;
            s.push(paren[i]);
            break;
        case ')':
            if (s.empty() || s.top() != '(') {
                valid = false;
                break;
            }
            s.pop();
            if (paren[i - 1] != ')' && paren[i - 1] != ']')
                res += tmp;
            tmp /= 2;
            break;
        case ']':
            if (s.empty() || s.top() != '[') {
                valid = false;
                break;
            }
            s.pop();
            if (paren[i - 1] != ')' && paren[i - 1] != ']')
                res += tmp;
            tmp /= 3;
        }
    }
    if (valid && s.empty()) cout << res;
    else cout << 0;
    return 0;
}