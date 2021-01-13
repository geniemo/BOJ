#include <iostream>
using namespace std;

int main(void)
{
    long long S;
    scanf("%lld", &S);

    int cnt = 0;
    for (long long i = 1; i <= S; i += (cnt + 1))
        cnt++;
    printf("%d", cnt);
    return 0;
}