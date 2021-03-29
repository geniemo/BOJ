#include <bits/stdc++.h>
using namespace std;

int N, r, c;
int pow_of_2[16] = {1, };

int getSeq(int x, int y, int seq, int n) {
    if (n == 0)
        return seq;
    int seq_unit = pow_of_2[n - 1] * pow_of_2[n - 1];
    // 왼쪽 위 사분할 사각형에 속할 때
    if (x <= r && r < x + pow_of_2[n - 1] && y <= c && c < y + pow_of_2[n - 1])
        return getSeq(x, y, seq, n - 1);
    // 오른쪽 위 사분할 사각형에 속할 때
    else if (x <= r && r < x + pow_of_2[n - 1] && y + pow_of_2[n - 1] <= c && c < y + pow_of_2[n])
        return getSeq(x, y + pow_of_2[n - 1], seq + seq_unit, n - 1);
    // 왼쪽 아래 사분할 사각형에 속할 때
    else if (x + pow_of_2[n - 1] <= r && r < x + pow_of_2[n] && y <= c && c < y + pow_of_2[n - 1])
        return getSeq(x + pow_of_2[n - 1], y, seq + 2 * seq_unit, n - 1);
    // 오른쪽 아래 사분할 사각형에 속할 때
    else
        return getSeq(x + pow_of_2[n - 1], y + pow_of_2[n - 1], seq + 3 * seq_unit, n - 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 15; i++)
        pow_of_2[i] = pow_of_2[i - 1] * 2;
    cin >> N >> r >> c;
    cout << getSeq(0, 0, 0, N);
    return 0;
}