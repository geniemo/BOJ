#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;
int depth[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    depth[N] = 1;
    q.push(N);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == 1)
        {
            cout << depth[1] - 1;
            break;
        }

        if (cur % 3 == 0 && depth[cur / 3] == 0)
        {
            depth[cur / 3] = depth[cur] + 1;
            q.push(cur / 3);
        }
        if (cur % 2 == 0 && depth[cur / 2] == 0)
        {
            depth[cur / 2] = depth[cur] + 1;
            q.push(cur / 2);
        }
        if (depth[cur - 1] == 0)
        {
            depth[cur - 1] = depth[cur] + 1;
            q.push(cur - 1);
        }
    }
    return 0;
}