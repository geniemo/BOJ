#include <iostream>
using namespace std;

int main(void)
{
    int N;
    scanf(" %d", &N);
    int cage[static_cast<const int>(N + 1)] = {1, 3, }; // number of ways to put in lion at proper location
    int tmp = 0;
    for (int i = 2; i <= N; i++)
    {
        tmp = (tmp + 2 * cage[i - 2]) % 9901;
        cage[i] = (cage[i - 1] + tmp + 2) % 9901;
    }
    printf("%d", cage[N]);
    return 0;
}