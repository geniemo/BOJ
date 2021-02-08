#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string infix, postfix;
    cin >> infix;
    stack<char> s;
    for (char c : infix) {
        if (isalpha(c))
            postfix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && priority(c) <= priority(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    cout << postfix;
    return 0;
}