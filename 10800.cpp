#include <bits/stdc++.h>
#define ti3     tuple<int, int, int>
#define COL     get<0>
#define SZ      get<1>
#define ID      get<2>
using namespace std;

int N;
ti3 ball[200005];
int sum;
int colAcc[200005];
int szAcc[2005];
int res[200005];

bool cmp(ti3& a, ti3& b) {
    if (SZ(a) == SZ(b))
        return COL(a) < COL(b);
    return SZ(a) < SZ(b);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> COL(ball[i]) >> SZ(ball[i]);
        ID(ball[i]) = i;
    }
    // 크기 기준으로 정렬
    sort(ball + 1, ball + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
        if (COL(ball[i]) == COL(ball[i - 1]) && SZ(ball[i]) == SZ(ball[i - 1])) // 앞의 공과 색과 크기 모두가 같다면 앞의 공과 res가 같다.
            res[ID(ball[i])] = res[ID(ball[i - 1])];
        else // 여태까지의 누적합에서 같은 색깔의 공들의 크기 누적합과 같은 크기의 공들의 크기 누적합을 뺀 값이 지금 공의 res
            res[ID(ball[i])] = sum - colAcc[COL(ball[i])] - szAcc[SZ(ball[i])];
        sum += SZ(ball[i]);
        colAcc[COL(ball[i])] += SZ(ball[i]);
        szAcc[SZ(ball[i])] += SZ(ball[i]);
    }
    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';
    return 0;
}