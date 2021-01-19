#include <iostream>
#include <queue>
#include <utility>
#define PAIR pair<pair<int, int>, int>
#define LOC first
#define X first
#define Y second
#define DIR second
using namespace std;

int N, M;
int map[50][50];
int visit[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; // 북, 동, 남, 서
enum {NORTH, EAST, SOUTH, WEST};

int GetLeftDir(int dir)
{
    switch (dir)
    {
        case NORTH: return WEST;
        case EAST: return NORTH;
        case SOUTH: return EAST;
        case WEST: return SOUTH;
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    PAIR robot;
    cin >> robot.LOC.X >> robot.LOC.Y >> robot.DIR;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    
    int cnt = 0;
    queue<PAIR> q;
    q.push(robot);
    while (!q.empty())
    {
        PAIR cur = q.front(); q.pop();
        if (visit[cur.LOC.X][cur.LOC.Y] == 0) // 처음 들린 거라면
        {
            visit[cur.LOC.X][cur.LOC.Y] = 1; // 현재 위치 청소
            cnt++;
        }

        int ndir = cur.DIR;
        int nx;
        int ny;
        bool isPushed = false;
        for (int i = 0; i < 4; i++) // 왼쪽으로 방향을 돌리며 청소할 곳이 있는지 확인
        {
            ndir = GetLeftDir(ndir);
            nx = cur.LOC.X + dx[ndir];
            ny = cur.LOC.Y + dy[ndir];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] == 0 && visit[nx][ny] == 0) // 청소를 아직 안한 길이라면
            {
                q.push({{nx, ny}, ndir}); // 청소하기위해 push
                isPushed = true;
                break;
            }
        }
        if (!isPushed) // 사방에 청소할 곳이 없었다면
        {
            nx = cur.LOC.X - dx[cur.DIR];
            ny = cur.LOC.Y - dy[cur.DIR]; // 뒤쪽 좌표
            if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] == 0) // 뒤에 공간이 있을 때
            {
                q.push({{nx, ny}, cur.DIR}); // 방향을 유지한채로 한 칸 뒤로 이동
                continue;
            }
            else // 뒤가 벽일 때
            {
                cout << cnt;
                break; // 작동 종료
            }
        }
    }
    return 0;   
}