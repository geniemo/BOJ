#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    long long fibo[2] = {0, 1};
    for (int i = 1; i < n; i++)
    {
        long long next = fibo[0] + fibo[1];
        fibo[0] = fibo[1];
        fibo[1] = next;
    }
    cout << fibo[1];
    return 0;
}