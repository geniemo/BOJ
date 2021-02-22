#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int mat[1001][1001]; // adjacency matrix
int visit[1001];

void DFS(int v)
{
    stack<int> s;
    s.push(v);

    while (!s.empty())
    {
        v = s.top(); s.pop();
        if (visit[v] == 1) continue;
        visit[v] = 1;
        cout << v << ' ';

        for (int i = N; i >= 1; i--)
        {
            if (visit[i] == 1 || mat[v][i] == 0)
                continue;
            s.push(i);
        }
    }
}

void BFS(int v)
{
    queue<int> q;
    visit[v] = 0;
    q.push(v);

    while (!q.empty())
    {
        v = q.front(); q.pop();
        cout << v << ' ';
        for (int i = 1; i <= N; i++)
        {
            if (visit[i] == 0 || mat[v][i] == 0)
                continue;
            visit[i] = 0;
            q.push(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y] = mat[y][x] = 1;
    }
    DFS(V);
    cout << '\n';
    BFS(V);
    return 0;
}