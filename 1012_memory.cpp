#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

queue<pair<int, int>> q;
int N, M, K;
int cabbage[50][50];
bool visited[50][50];

void init()
{
    while (!q.empty()) q.pop();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            cabbage[i][j] = 0;
        }
    }
}

bool IsValidLocation(int x, int y)
{
    return (0 <= x && x <= N && 0 <= y && y <= M);
}

void bfs(int xx, int yy)
{
    q.push({xx, yy});
    visited[xx][yy] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsValidLocation(nx, ny) && !visited[nx][ny] && cabbage[nx][ny] == 1)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main(void)
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        init();
        cin >> M >> N >> K;
        int cnt = 0;
        for (int j = 0; j < K; j++)
        {
            int x, y;   
            cin >> y >> x;
            cabbage[x][y] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (cabbage[i][j] == 1 && !visited[i][j])
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}