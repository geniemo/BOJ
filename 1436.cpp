#include <iostream>
using namespace std;

bool BlockBuster(int n)
{
    int seq_cnt = 0;
    while (n > 0)
    {
        if (n % 10 == 6) // if digit is 6
            seq_cnt++;
        else // not six
            seq_cnt = 0; // 6 should be successive
        if (seq_cnt >= 3) // three "6" are successive -> "666"! blockbuster!
            return true;
        n /= 10;
    }
    return false;
}

int main(void)
{
    int n;
    int num = 666; // first blockbuster number
    int cnt = 0;
    cin >> n;
    
    while (1)
    {
        cnt = (BlockBuster(num)) ? cnt + 1 : cnt;
        if (cnt == n)
            break;
        num++;
    }
    cout << num;
}