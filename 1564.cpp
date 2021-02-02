#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    long long res = 1;
    for (int i = 1; i <= N; i++)
    {
        res *= i;
        while (res % 10 == 0)
            res /= 10;
        res %= 1000000000000;
    }
    res %= 100000;
    if (0 <= res && res < 10)
        cout << "0000" << res;
    else if (10 <= res && res < 100)
        cout << "000" << res;
    else if (100 <= res && res < 1000)
        cout << "00" << res;
    else if (1000 <= res && res < 10000)
        cout << "0" << res;
    else
        cout << res;
    return 0;
}