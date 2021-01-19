#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define PAIR pair<pair<int, int>, int>
#define LOC first
#define X first
#define Y second
#define DIR second
using namespace std;

int M, N;
int map[101][101];
int depth[101][101][5];
int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 }; // tmp, 1: 동, 2: 서, 3: 남, 4: 북
enum {EAST = 1, WEST, SOUTH, NORTH};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    queue<PAIR> q;
    PAIR start; // 시작 위치, 방향
    PAIR dst; // 목적지, 방향
    cin >> start.LOC.X >> start.LOC.Y >> start.DIR;
    cin >> dst.LOC.X >> dst.LOC.Y >> dst.DIR;

    q.push(start);
    depth[start.LOC.X][start.LOC.Y][start.DIR] = 1;
    while (!q.empty())
    {
        PAIR cur = q.front(); q.pop();
        int curD = depth[cur.LOC.X][cur.LOC.Y][cur.DIR];
        if (cur == dst)
        {
            cout << curD - 1;
            break;
        }

        // TURN
        if (cur.DIR == EAST || cur.DIR == WEST) // 지금 동, 서를 바라보고 있고
        {
            if (depth[cur.LOC.X][cur.LOC.Y][SOUTH] == 0) // 지금 위치에서 남쪽을 바라본 적이 없으면
            {
                depth[cur.LOC.X][cur.LOC.Y][SOUTH] = curD + 1; // 방향을 남쪽으로 돌리고
                q.push({{cur.LOC.X, cur.LOC.Y}, SOUTH}); // 돌린 경우도 조사하기 위해 push
            }
            if (depth[cur.LOC.X][cur.LOC.Y][NORTH] == 0) // 지금 위치에서 북쪽을 바라본 적이 없을 때도 똑같이 push
            {
                depth[cur.LOC.X][cur.LOC.Y][NORTH] = curD + 1;
                q.push({{cur.LOC.X, cur.LOC.Y}, NORTH});
            }
        }
        else // 지금 남, 북을 바라보고 있고
        {
            if (depth[cur.LOC.X][cur.LOC.Y][EAST] == 0) // 지금 위치에서 동쪽을 바라본 적이 없으면
            {
                depth[cur.LOC.X][cur.LOC.Y][EAST] = curD + 1; // 방향을 동쪽으로 돌리고
                q.push({{cur.LOC.X, cur.LOC.Y}, EAST}); // 돌린 경우도 조사하기 위해 push
            }
            if (depth[cur.LOC.X][cur.LOC.Y][WEST] == 0) // 지금 위치에서 서쪽을 바라본 적이 없을 때도 똑같이 push
            {
                depth[cur.LOC.X][cur.LOC.Y][WEST] = curD + 1;
                q.push({{cur.LOC.X, cur.LOC.Y}, WEST});
            }
        }

        // GO k, k 는 1, 2, 3
        for (int k = 1; k <= 3; k++)
        {
            int nx = cur.LOC.X + k * dx[cur.DIR];
            int ny = cur.LOC.Y + k * dy[cur.DIR];
            if (nx < 1 || ny < 1 || nx > M || ny > N) // 맵을 벗어나서 진행하고 있다면 루프 중지
                break;
            if (map[nx][ny] == 1) // 벽이 있다면 더이상 앞으로 나아가지 못하게 루프 중지
                break;
            if (depth[nx][ny][cur.DIR] == 0) // 아직 다음 위치를 들린 적이 없을 때
            {
                depth[nx][ny][cur.DIR] = curD + 1; // 다음 위치로 이동
                q.push({{nx, ny}, cur.DIR});
            }
        }
    }
    return 0;
}