#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> com[101];
bool visit[101];
int n, m, cnt;

void DFS(int r)
{
    stack<int> s;
    s.push(r);
    visit[r] = true;

    while (!s.empty())
    {
        int c = s.top(); s.pop();
        for (int i = 0; i < com[c].size(); i++)
        {
            if (visit[com[c][i]] == false)
            {
                s.push(com[c][i]);
                visit[com[c][i]] = true;
                cnt++;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    DFS(1);
    cout << cnt;
    return 0;
}