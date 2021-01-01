#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(void)
{
    int N;
    int S = 0;
    scanf(" %d", &N);
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf(" %d", &num);
        v1.push_back(num);
    }
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf(" %d", &num);
        v2.push_back(num);
    }
    // sort v1 ascending order
    sort(v1.begin(), v1.end());
    // sort v2 descending order
    sort(v2.begin(), v2.end(), greater<int>());
    // multiply all values in the vector v1 and v2
    for (int i = 0; i < N; i++)
        S += (v1[i] * v2[i]);
    printf("%d", S);
    return 0;
}
