#include <iostream>
using namespace std;

int L = 1, P = 1, V = 1; // V일의 휴가, 연속하는 P일중 L일동안만 캠핑 가능
int res;
int cnt;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        cnt++;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;
        res = (V % P < L) ? V / P * L + V % P : V / P * L + L;
        cout << "Case " << cnt << ": " << res << '\n';
    }
    return 0;
}