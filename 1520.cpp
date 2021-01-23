#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define PAIR pair<pair<int, int>, int>
#define LOC first
#define X first
#define Y second
#define H second
using namespace std;

int M, N;
int map[500][500];
int cnt[500][500];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1}; // 아, 위, 오, 왼

struct cmp
{
    bool operator()(PAIR& a, PAIR& b)
    {
        return b.H > a.H; // 높이가 더 높은 것이 우선순위가 높다.
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<PAIR, vector<PAIR>, cmp> pq;
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            pq.push({{i, j}, map[i][j]});
        }
    }

    cnt[0][0] = 1;
    while (!pq.empty())
    {
        PAIR cur = pq.top(); pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.LOC.X + dx[i];
            int ny = cur.LOC.Y + dy[i];
            if (0 <= nx && nx < M && 0 <= ny && ny < N)
            {
                if (cur.H < map[nx][ny])
                    cnt[cur.LOC.X][cur.LOC.Y] += cnt[nx][ny];
            }
        }
    }
    cout << cnt[M - 1][N - 1];
    return 0;
}