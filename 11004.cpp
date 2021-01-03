#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> v;
    int N, K; // N is the number of input, we need to print K-th smallest number
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf(" %d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end()); // sort by ascending order
    cout << v[K - 1];
    return 0;
}