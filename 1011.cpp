#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int T;
    scanf(" %d", &T); // number of test case
    for (int i = 0; i < T; i++)
    {
        int x, y;
        scanf(" %d %d", &x, &y);
        int dist = y - x; // dist of two planet
        int low = pow(static_cast<int>(sqrt(dist)), 2); // dist cannot be lower than low
        int lowSqrt = sqrt(low);
        int high = pow(static_cast<int>(sqrt(dist)) + 1, 2); // dist cannot be higher than high
        if (dist == low)
            printf("%d\n", 2 * lowSqrt - 1);
        else if (dist <= (static_cast<long long>(low) + high) / 2)
            printf("%d\n", 2 * lowSqrt);
        else
            printf("%d\n", 2 * lowSqrt + 1);
    }
    return 0;
}