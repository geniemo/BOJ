#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int N, K;
    scanf(" %d %d", &N, &K);
    int levelMemo[100001] = {0, }; // for memoization
    queue<int> q;
    q.push(N);
    while (true)
    {
        int cur = q.front(); q.pop();
        if (cur == K)
        {
            printf("%d", levelMemo[cur]);
            return 0;
        }

        if (cur - 1 >= 0 && levelMemo[cur - 1] == 0) // walk left
        {
            q.push(cur - 1);
            levelMemo[cur - 1] = levelMemo[cur] + 1;
        } 
        if (cur + 1 <= 100000 && levelMemo[cur + 1] == 0) // walk right
        {
            q.push(cur + 1);
            levelMemo[cur + 1] = levelMemo[cur] + 1;
        }
        if (cur * 2 <= 100000 && levelMemo[cur * 2] == 0) // warp
        {
            q.push(cur * 2);
            levelMemo[cur * 2] = levelMemo[cur] + 1;
        } 
    }
    return 0;
}