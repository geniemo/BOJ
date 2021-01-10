#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{   
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        scanf(" %d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double dist = sqrt( pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2) );
        if (dist == 0 && r1 == r2)
            printf("-1\n");
        else if (dist > r1 + r2 || dist < abs(r1 - r2))
            printf("0\n");
        else if (dist == r1 + r2 || dist == abs(r1 - r2))
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}