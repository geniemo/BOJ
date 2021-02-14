#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int t_ = 0; t_ < t; t_++) {
        int n;
        cin >> n;
        unordered_set<string> phone;
        for (int i = 0; i < n; i++) {
            string p;
            cin >> p;
            phone.insert(p);
        }
        bool is_consistent = true;
        for (auto it = phone.begin(); it != phone.end() && is_consistent; it++) {
            string p_;
            for (int j = 0; j < it->length() - 1; j++) {
                p_ += (*it)[j];
                if (phone.find(p_) != phone.end()) {
                    is_consistent = false;
                    break;
                }
            }
        }
        cout << (is_consistent ? "YES\n" : "NO\n");
    }
    return 0;
}