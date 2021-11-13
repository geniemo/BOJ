#include <bits/stdc++.h>
using namespace std;

int n;
int A[1001];
long long cnt;

void getAddCnt(int st, int en, int beforeMx) {
    int mx = *max_element(A + st, A + en);
    int mx_idx = find(A + st, A + en, mx) - A;
    if (st <= mx_idx - 1)
        getAddCnt(st, mx_idx, mx);
    if (mx_idx + 1 < en)
        getAddCnt(mx_idx + 1, en, mx);
    cnt += beforeMx - mx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    getAddCnt(0, n, *max_element(A, A + n));
    cout << cnt;
    return 0;
}