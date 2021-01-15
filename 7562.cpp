#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int arr[301][301];
bool checked[301][301];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int I; // 체스판 한 변 길이
queue<pair<int, int>> q;
int srcX, srcY, dstX, dstY;

void BFS(int a, int b)
{
    q.push({a, b});
    checked[a][b] = true;
    while (!q.empty())
    {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        if (x == dstX && y == dstY)
        {
            cout << arr[x][y] << '\n';
            while (!q.empty())
                q.pop();
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < I && 0 <= ny && ny < I)
            {
                if (checked[nx][ny] == false)
                {
                    checked[nx][ny] = true;
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> I;
        cin >> srcX >> srcY >> dstX >> dstY;

        for (int i = 0; i < 301; i++)
        {
            fill(arr[i], arr[i] + 301, 0);
            fill(checked[i], checked[i] + 301, false);
        }

        BFS(srcX, srcY);
    }
    return 0;
}