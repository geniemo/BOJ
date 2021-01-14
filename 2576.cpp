#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int oddSum = 0;
    int min = 100;
    for (int i = 0; i < 7; i++)
    {
        int num; cin >> num;
        if (num % 2 != 0)
        {
            oddSum += num;
            min = (num < min) ? num : min;
        }
    }
    if (oddSum == 0) cout << -1;
    else
    {
        cout << oddSum << '\n';
        cout << min;
    }
    return 0;
}