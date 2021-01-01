#include <iostream>
using namespace std;

int DigitCnt(int n) // cal digits
{
    int cnt = 0;
    while ( n > 0 )
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int DigitSum(int n) // add all digits
{
    int sum = 0;
    int m = 10;
    while ( n > 0 )
    {
        int add = n % m;
        sum += add;
        n /= m;
    }
    return sum;
}

int Decomp(int n)
{
    int start = n - DigitCnt(n) * 9; // Decomp of n can't be smaller than n - DigitCnt(n) * 9
    int dest = n - 1; // also can't be bigger than n - 1
    for (int i = start; i <= dest; i++)
    {
        int result = i + DigitSum(i);
        if (result == n)
            return i;
    }
    return 0;
}

int main(void)
{
    int n;
    cin >> n;
    cout << Decomp(n);
    return 0;
}