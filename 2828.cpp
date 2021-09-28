#include <iostream>
using namespace std;

int M, N, J;
int p;
int cur = 1;
int cnt;

void go() {
    // 움직일 필요가 없을 때
    if (cur <= p && p <= cur + M - 1)
        return;
    // 오른쪽으로 움직여야 할 때
    if (cur + M - 1 < p) {
        cnt += (p - M + 1) - cur;
        cur = p - M + 1;
    }
    // 왼쪽으로 움직여야 할 때
    else {
        cnt += cur - p;
        cur = p;
    }
}

int main(void) {
    cin >> N >> M >> J;
    while (J--) {
        cin >> p;
        go();
    }
    cout << cnt;
    return 0;
}