#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int N;
    scanf(" %d", &N);
    int tmp = 2;
    while (tmp <= sqrt(N))
    {
        if (N % tmp == 0)
        {
            printf("%d\n", tmp);
            N /= tmp;
        }
        else
            tmp++;
    }
    if (N != 1)
        printf("%d\n", N);
    return 0;
}