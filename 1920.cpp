#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int N;
    scanf(" %d", &N);

    map<int, bool> A;
    for (int i = 0; i < N; i++)
    {
        int num; scanf(" %d", &num);
        A[num] = true;
    }

    int M;
    scanf(" %d", &M);
    for (int i = 0; i < M; i++)
    {
        int num; scanf(" %d", &num);
        printf("%d\n", A[num]);
    }
    return 0;
}