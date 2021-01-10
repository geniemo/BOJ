#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int N;
    scanf(" %d", &N);
    int cnt[static_cast<const int>(N + 1)] = {0, 1, };
    for (int i = 2; i <= N; i++)
    {
        int minimum = 0x7fffffff;
        for (int j = 1; j <= sqrt(i); j++)
        {
            int tmp = 1 + cnt[i - (j * j)];
            minimum = min(tmp, minimum);
        }
        cnt[i] = minimum;    
    }
    printf("%d", cnt[N]);
    return 0;
}