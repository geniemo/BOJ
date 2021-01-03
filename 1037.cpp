#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    scanf(" %d", &n);
    vector<int> divisors;
    for (int i = 0; i < n; i++)
    {
        int divisor;
        scanf(" %d", &divisor);
        divisors.push_back(divisor);
    }
    sort(divisors.begin(), divisors.end()); // sort by ascending order
    printf("%d", divisors[0] * divisors[n - 1]); // number N is smallest real divisor * biggest real divisor
    return 0;
}