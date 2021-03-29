#include <bits/stdc++.h>
using namespace std;

int N;
int M;
vector<int> button = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int mn;

void calMin(int cur, int cnt) {
    if (cur > N)
        return;
    int next;
    for (auto i : button) {
        next = 10 * cur + i;
        mn = min(mn, abs(N - next) + cnt + 1);
        if (next != 0)
            calMin(next, cnt + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    int tmp;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        button.erase(find(button.begin(), button.end(), tmp));
    }
    mn = abs(N - 100);
    calMin(0, 0);
    cout << mn;
    return 0;
}