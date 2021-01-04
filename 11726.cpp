#include <iostream>
using namespace std;

// return the number of ways to fill 2*n blocks % 10007
int tile(int n)
{
    int tile[2] = {0, 1};
    // ways to fill 2*n == ways to fill 2*(n-1) + ways to fill 2*(n-2)
    for (int i = 0; i < n; i++)
    {
        int next = (tile[0] + tile[1]) % 10007;
        tile[0] = tile[1];
        tile[1] = next;
    }
    return tile[1];
}


int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", tile(n));
    return 0;
}