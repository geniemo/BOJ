#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int main(void)
{
    int coinMemo[10001] = {0, };
    int n, k; // n: kind of coin, k: won
    scanf(" %d %d", &n, &k);
    set<int, greater<int>> coins; // insert following descending order
    for (int i = 0; i < n; i++)
    {
        int coin;
        scanf(" %d", &coin);
        if (coin <= k) coins.insert(coin);
    }

    for (set<int, greater<int>>::const_iterator i = coins.begin(); i != coins.end(); i++)
    {
        queue<int> q;
        q.push(*i); coinMemo[*i] = 1;
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            if (cur == k)
            {
                printf("%d", coinMemo[cur]);
                return 0;
            }
            for (set<int, greater<int>>::const_iterator c = coins.begin(); c != coins.end(); c++)
            {
                if (cur + *c <= k)
                {
                    q.push(cur + *c);
                    coinMemo[cur + *c] = coinMemo[cur] + 1;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
