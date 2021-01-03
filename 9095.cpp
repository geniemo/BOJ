#include <iostream>
using namespace std;

int MakeBy123(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    else // n > 4
        return MakeBy123(n - 1) + MakeBy123(n - 2) + MakeBy123(n - 3);
}

int main(void)
{
    int T; // num of test cases
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << MakeBy123(n) << endl;
    }
    return 0;
}