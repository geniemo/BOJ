#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        string ipt;
        cin >> ipt;
        if (ipt == "push")
        {
            int item;
            cin >> item;
            q.push(item);
        }
        else if (ipt == "pop")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
            q.pop();
        }
        else if (ipt == "size")
            cout << q.size() << '\n';
        else if (ipt == "empty")
            cout << q.empty() << '\n';
        else if (ipt == "front")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
        }
        else if (ipt == "back")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
    }
    return 0;
}