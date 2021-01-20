#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int N;
int map[20][20];
int depth[20][20];
int s = 2; // 상어의 크기
int ate; // 상어가 먹은 물고기 수
int time; // 지나간 시간

int dx[] = {-1, 0, 0, 1}; 
int dy[] = {0, -1, 1, 0}; // 위, 왼, 오, 아

void ClearDepth()
{
    for (int i = 0; i < N; i++)
        fill(depth[i], depth[i] + N, 0);
}

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b) // b가 더 우선순위가 높은가?
    {
        if (depth[b.X][b.Y] != depth[a.X][a.Y]) // 새로 push된 것과 거리가 다르다면
            return depth[b.X][b.Y] < depth[a.X][a.Y]; // 가까울수록 우선순위가 높다
        else// 새로 push된 것과 거리가 같다면
        {
            if (b.X != a.X) // 새로 push된 것과 x좌표가 다르다면
                return b.X < a.X; // 더 위에 있는 것이 우선순위가 높다
            else // x좌표도 같다면
                return b.Y < a.Y; // 더 왼쪽에 있는 것이 우선순위가 높다
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sx, sy;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                sx = i;
                sy = j;
                map[i][j] = 0;
            }
        }
    }

    while (1)
    {
        ClearDepth();

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int sx_ = sx, sy_ = sy;
        depth[sx][sy] = 1;
        pq.push({sx, sy}); // 물고기를 먹고 난 다음의 상어의 위치를 push, BFS 사용
        while (!pq.empty())
        {
            pair<int, int> cur = pq.top(); pq.pop();
            if (0 < map[cur.X][cur.Y]) // 생선이 있을 때
            {
                if (map[cur.X][cur.Y] < s) // 먹을 수 있는 생선일 때
                {
                    ate++;
                    map[cur.X][cur.Y] = 0; // 생선을 먹는다
                    sx = cur.X;
                    sy = cur.Y;
                    if (s == ate)
                    {
                        s++;
                        ate = 0;
                    }
                    time += depth[cur.X][cur.Y] - 1;
                    break;
                }
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (0 <= nx && nx < N && 0 <= ny && ny < N && depth[nx][ny] == 0) // 들른 적이 없는 올바른 길이면서
                {
                    if (map[nx][ny] <= s) // 빈 길이거나 상어보다 크기가 작거나 같은 물고기라면
                    {
                        depth[nx][ny] = depth[cur.X][cur.Y] + 1; // 그 위치를 방문
                        pq.push({nx, ny});
                    }
                }
            }
        }
        if (sx_ == sx && sy_ == sy) // 더이상 먹을 물고기가 없다면 종료
        {
            cout << time;
            break;
        }
    }
    return 0;
}