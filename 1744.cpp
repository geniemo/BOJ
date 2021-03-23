#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> ps;
deque<int> ng;
int n1, n2;
int res;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp > 0) ps.push_back(tmp);
        else ng.push_back(tmp);
    }
    sort(ps.begin(), ps.end());
    sort(ng.begin(), ng.end());
    while (ps.size() > 1) {
        n1 = ps.back();
        ps.pop_back();
        n2 = ps.back();
        ps.pop_back();
        if (n1 == 1 || n2 == 1)
            res += n1 + n2;
        else
            res += n1 * n2;
    }
    if (!ps.empty()) {
        res += ps.back();
        ps.pop_back();
    }
    while (ng.size() > 1) {
        n1 = ng.front();
        ng.pop_front();
        n2 = ng.front();
        ng.pop_front();
        res += n1 * n2;
    }
    if (!ng.empty()) {
        res += ng.front();
        ng.pop_front();
    }
    cout << res;
    return 0;
}