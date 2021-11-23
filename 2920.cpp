#include <bits/stdc++.h>
using namespace std;
int a, cnt;
int main(void) {
    for (int i = 1; i <= 8; i++) {
        cin >> a;
        cnt = a == i ? cnt + 1 : a + i == 9 ? cnt - 1 : cnt;
    }
    cout << (cnt == 8 ? "ascending" : cnt == -8 ? "descending" : "mixed");
    return 0;
}