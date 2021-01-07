#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    scanf(" %d", &N);
    int* price = new int[N + 1];
    for (int i = 1; i <= N; i++)
        scanf(" %d", &price[i]);
    
    int* maxMemo = new int[N + 1];
    maxMemo[0] = 0;
    maxMemo[1] = price[1];
    for (int i = 2; i <= N; i++)
    {
        int M = -1;
        for (int j = 1; j <= i; j++)
            M = max(M, price[j] + maxMemo[i - j]);
        maxMemo[i] = M;
    }

    printf("%d", maxMemo[N]);
    return 0;
}