#include <iostream>
using namespace std;

int main(void)
{
    char row[9];
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> row;
        // if i is even, row[i][even] is white block, if i is odd, row[i][odd] is white block
        for (int j = i % 2; j < 8; j += 2)
            cnt = (row[j] == 'F') ? cnt + 1 : cnt;
    }
    cout << cnt;
    return 0;
}