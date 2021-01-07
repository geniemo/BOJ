#include <iostream>
#include <queue>
#include <utility>
using namespace std;

enum {NO, YES}; // 0, 1

int main(void)
{
    int N;
    scanf(" %d", &N);
    const int _N = N;
    int org[_N][_N];
    int des[_N][_N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int is_path;
            scanf(" %d", &is_path);
            org[i][j] = is_path;
            des[i][j] = is_path;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (org[i][j] == YES)
            {
                queue<int> q;
                q.push(j);

                while (!q.empty())
                {
                    int cur = q.front(); q.pop();
                    des[i][cur] = YES;

                    for (int k = 0; k < N; k++)
                    {
                        if (org[cur][k] == 1 && des[i][k] == false) // can go cur to k, not visit k-th row yet
                            q.push(k);
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", des[i][j]);
        printf("\n");
    }
    return 0;
}