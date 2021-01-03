#include <iostream>
using namespace std;

// it calculate M combination N
// M * (M - 1) * ... * (M - N + 1) / (N)!
long long combination(int N, int M)
{
    long long numerator = 1;
    long long denominator = 1;

    if (N > (M / 2)) N = M - N; // m combination n == m combination m-n
    // cal numerator loop
    for (int i = M; i >= M - N + 1; i--) // M * (M - 1) * ... * (M - N + 1)
        numerator *= i;
    // cal denominator loop
    for (int i = 1; i <= N; i++) // N!
        denominator *= i;

    return numerator / denominator;
}

int main(void)
{
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++)
    {
        int N, M;
        scanf(" %d %d", &N, &M);
        printf("%lld\n", combination(N, M));
    }
    return 0;
}