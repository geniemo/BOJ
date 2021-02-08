#include <bits/stdc++.h>
using namespace std;

int G, P;
set<int> rem; // 남아있는 비행장
int cnt;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> G >> P;
    for (int i = 1; i <= G; i++)
        rem.insert(i);
    for (int i = 0; i < P; i++) {
        int seq;
        cin >> seq;
        auto it = rem.upper_bound(seq); // seq보다 큰 최소의 것
        if (it == rem.begin()) break; // seq이하인 것이 없다면 종료
        it--; // seq이하인 것이 있으므로
        rem.erase(it); // seq이하인 것 중 게이트 번호가 최대인 게이트에 도킹
        cnt++;
    }
    cout << cnt;
    return 0;
}