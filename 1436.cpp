#include <iostream>
using namespace std;

bool BlockBuster(int n)
{
    int six_cnt = 0;
    int seq_cnt = 0;
    while (n > 0)
    {
        if (n % 10 == 6)
        {
            six_cnt++;
            seq_cnt++;
        }
        else
        {
            six_cnt = 0;
            seq_cnt = 0;
        }
        if (six_cnt == 3 && seq_cnt == 3)
            return true;
        n /= 10;
    }
    return false;
}

int main(void)
{
    int n;
    int num = 666;
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