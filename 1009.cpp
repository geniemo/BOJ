#include <iostream>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        int res = 1;
        cin >> a >> b;
        for (int j = 0; j < b; j++)
            res = (res * a) % 10;
        if (res == 0)
            cout << 10 << endl;
        else
            cout << res << endl;
    }
    return 0;
}