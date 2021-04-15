#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> dq;
string command;
int dat;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push_front") {
            cin >> dat;
            dq.push_front(dat);
        }
        else if (command == "push_back") {
            cin >> dat;
            dq.push_back(dat);
        }
        else if (command == "pop_front") {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        else if (command == "pop_back") {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        else if (command == "size") {
            cout << dq.size() << "\n";
        }
        else if (command == "empty") {
            cout << dq.empty() << "\n";
        }
        else if (command == "front") {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.front() << "\n";
        }
        else if (command == "back") {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.back() << "\n";
        }
    }
    return 0;
}