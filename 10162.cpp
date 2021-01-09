#include <iostream>
using namespace std;

int main(void)
{
    int A = 300, B = 60, C = 10;
    int T;
    scanf(" %d", &T);
    if (T % 10 == 0)
        printf("%d %d %d", T / A, (T % A) / B, ((T % A) % B) / C);
    else
        printf("-1");
    return 0;
}