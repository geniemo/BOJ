#include <bits/stdc++.h>
#define     PAIR    pair<int, int>
#define     X       first
#define     Y       second
using namespace std;

int n;
int sumX[1000005];
int sumY[1000005];

int getMx() {
    for (int i = 1; i < 1000005; i++) {
        sumX[i] += sumX[i - 1];
        sumY[i] += sumY[i - 1];
    }
    return max(*max_element(sumX, sumX + 1000005), *max_element(sumY, sumY + 1000005));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    PAIR first_pos, cur, tmp;
    cin >> first_pos.X >> first_pos.Y;
    cur = first_pos;
    for (int i = 1; i < n; i++) {
        tmp = cur;
        cin >> cur.X >> cur.Y;
        // 이전 점과 수평선을 만든다면 horV에, 아니라면 verV에
        if (tmp.X == cur.X) {
            sumY[min(tmp.Y + 500000, cur.Y + 500000)]++;
            sumY[max(tmp.Y + 500000, cur.Y + 500000)]--;
        }
        else {
            sumX[min(tmp.X + 500000, cur.X + 500000)]++;
            sumX[max(tmp.X + 500000, cur.X + 500000)]--;
        }
    }
    if (first_pos.X == cur.X) {
        sumY[min(first_pos.Y + 500000, cur.Y + 500000)]++;
        sumY[max(first_pos.Y + 500000, cur.Y + 500000)]--;
    }
    else {
        sumX[min(first_pos.X + 500000, cur.X + 500000)]++;
        sumX[max(first_pos.X + 500000, cur.X + 500000)]--;
    }
    cout << getMx();
    return 0;
}