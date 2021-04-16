#include <bits/stdc++.h>
using namespace std;

int T;
string p;
int n;
deque<int> dq;
bool is_reversed = false;

void init() {
    dq.clear();
    is_reversed = false;
}

void print() {
    if (dq.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    if (is_reversed) {
        for (int i = dq.size() - 1; i > 0; i--)
            cout << dq[i] << ",";
        cout << dq.front();
    }
    else {
        for (int i = 0; i < dq.size() - 1; i++)
            cout << dq[i] << ",";
        cout << dq.back();
    }
    cout << "]\n";
}

void go() {
    for (char c : p) {
        if (c == 'R') {
            is_reversed = !is_reversed;
            continue;
        }
        if (dq.empty()) {
            cout << "error\n";
            return;
        }
        if (is_reversed)
            dq.pop_back();
        else
            dq.pop_front();
    }
    print();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    char tmp;
    int x;
    while (T--) {
        init();
        cin >> p;
        cin >> n;
        if (n == 0)
            cin >> tmp >> tmp;
        else {
            for (int i = 0; i < n; i++) {
                cin >> tmp >> x;
                dq.push_back(x);
            }
            cin >> tmp;
        }
        go();
    }
    return 0;
}