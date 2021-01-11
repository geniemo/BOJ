#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define MAX_VALUE   1001

int N, M, V;
int mat[MAX_VALUE][MAX_VALUE]; // adjacency matrix
int visit[MAX_VALUE];

void DFS(int v)
{
    stack<int> s;
    s.push(v);

    while (!s.empty())
    {
        v = s.top(); s.pop();
        if (visit[v] == 1) continue;
        else visit[v] = 1;
        printf("%d ", v);

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
    q.push(v);
    visit[v] = 0;

    while (!q.empty())
    {
        v = q.front(); q.pop();
        printf("%d ", v);
        for (int i = 1; i <= N; i++)
        {
            if (visit[i] == 0 || mat[v][i] == 0)
                continue;
            q.push(i);
            visit[i] = 0;
        }
    }
}

int main(void)
{
    int x;
    int y;
    scanf(" %d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++)
    {
        scanf(" %d %d", &x, &y);
        mat[x][y] = mat[y][x] = 1;
    }
    DFS(V);
    printf("\n");
    BFS(V);
    return 0;
}