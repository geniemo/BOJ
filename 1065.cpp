#include <iostream>
#include <cmath>
using namespace std;

bool IsHan(int n)
{
    int d = n % 10 - n / 10 % 10;
    while (n >= 10)
    {
        int d_ = n % 10 - n / 10 % 10;
        if (d_ != d)
            return false;
        n /= 10;
    }
    return true;
}

int main(void)
{
    int N;
    scanf(" %d", &N);

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i < 100 || IsHan(i))
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}