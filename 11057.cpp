#include <iostream>
using namespace std;

int main(void)
{
    int N;
    scanf(" %d", &N);

    int ascent[1001][10] = { {1, } };
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k <= j; k++)
                ascent[i][j] = (ascent[i][j] + ascent[i - 1][k]) % 10007;
    
    int ascCnt = 0;
    for (int i = 0; i < 10; i++)
        ascCnt = (ascCnt + ascent[N][i]) % 10007;
    printf("%d", ascCnt);

    return 0;
}