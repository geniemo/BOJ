#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

void clear(std::queue<int> &q)
{
   queue<int> empty;
   swap(q, empty);
}

int main(void)
{
    int n, k; // n: kind of coin, k: won
    scanf(" %d %d", &n, &k);
    set<int, greater<int>> coins; // insert following descending order
    for (int i = 0; i < n; i++)
    {
        int coin;
        scanf(" %d", &coin);
        if (coin <= k) coins.insert(coin);
    }

    int min = 10001;
    for (set<int, greater<int>>::const_iterator i = coins.begin(); i != coins.end(); i++)
    {
        int coinMemo[10001] = {0, };
        queue<int> q;
        q.push(*i); coinMemo[*i] = 1;
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            if (cur == k)
            {
                min = (coinMemo[cur] < min) ? coinMemo[cur] : min;
                break;
            }

            for (set<int, greater<int>>::const_iterator c = coins.begin(); c != coins.end(); c++)
            {
                if (cur + *c <= k && coinMemo[cur + *c] == 0)
                {
                    q.push(cur + *c);
                    coinMemo[cur + *c] = coinMemo[cur] + 1;
                }
            }
        }
        clear(q);
    }

    if (min == 10001) // no way to make k won
        printf("-1");
    else
        printf("%d", min);
    return 0;
}
