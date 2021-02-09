#include <bits/stdc++.h>
using namespace std;

string str, res;
deque<char> dq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    getline(cin, str);
    for (char c : str) {
        if (isalpha(c) || isdigit(c))
            dq.push_back(c);
        else if (c == '<') {
            while (!dq.empty()) {
                res += dq.back();
                dq.pop_back();
            }
            dq.push_back(c);
        }
        else if (c == '>') {
            while (!dq.empty()) {
                res += dq.front();
                dq.pop_front();
            }
            res += c;
        }
        else if (dq.front() == '<')
            dq.push_back(c);
        else if (c == ' ') {
            while (!dq.empty()) {
                res += dq.back();
                dq.pop_back();
            }
            res += c;
        }
    }
    while (!dq.empty()) {
        res += dq.back();
        dq.pop_back();
    }
    cout << res;
}