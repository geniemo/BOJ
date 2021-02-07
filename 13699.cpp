#include <iostream>
using namespace std;

long long t[36] = {1, 1, };
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i / 2; j++)
            t[i] += t[j] * t[i - (j + 1)];
        t[i] *= 2;
        if (i % 2 != 0)
            t[i] += t[i / 2] * t[i / 2];
    }
    cout << t[n];
    return 0;
}