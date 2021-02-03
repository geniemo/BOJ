#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[1000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> p[i];
    sort(p, p + N);

    int res = 0;
    for (int i = 0; i < N; i++)
        res += p[i] * (N - i);
    cout << res;
    return 0;
}