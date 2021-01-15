#include <iostream>
#include <deque>
#include <queue>
#define X first
#define Y second
using namespace std;

enum { EMPTY, APPLE, WARM };

int N, K, L;
int map[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 }; // 오, 왼, 아, 위
queue<pair<int, char>> q;

void TurnDirection(int& rdir, char C)
{
    if (C == 'L') // 왼쪽
    {
        if (rdir == 0) rdir = 3;
        else if (rdir == 1) rdir = 2;
        else if (rdir == 2) rdir = 0;
        else if (rdir == 3) rdir = 1;
    }
    else // 오른쪽
    {
        if (rdir == 0) rdir = 2;
        else if (rdir == 1) rdir = 3;
        else if (rdir == 2) rdir = 1;
        else if (rdir == 3) rdir = 0;
    }
}

int GameEndAt()
{
    deque<pair<int, int>> warm; 
    warm.push_front({ 1, 1 });
    map[1][1] = WARM; // 1행 1열에 길이 1짜리 벌레
    int x = 1, y = 1;
    int dir = 0; // 오른쪽 방향
    pair<int, char> nTurn;
    if (!q.empty())
    {
        nTurn = q.front();
        q.pop();
    }
    int time = 0;

    while (1)
    {
        time++; // 시간 증가
        int nx = warm[0].X + dx[dir]; // 다음 행
        int ny = warm[0].Y + dy[dir]; // 다음 열
        // 벽과 만났거나 자신의 몸과 만났다면 게임 오버
        if (map[nx][ny] == WARM || nx < 1 || ny < 1 || nx > N || ny > N)
            return time;
        // 이동할 위치에 사과가 있다면 머리만 이동
        else if (map[nx][ny] == APPLE)
        {
            map[nx][ny] = WARM;
            warm.push_front({ nx, ny });
        }
        // 벽과 만나지도 않고 사과가 있지도 않다면 머리를 이동 후 나머지도 따라서 이동
        else
        {
            map[nx][ny] = WARM;
            warm.push_front({ nx, ny });
            map[warm[warm.size() - 1].X][warm[warm.size() - 1].Y] = EMPTY;
            warm.pop_back();
        }
        // 바꿀 시간이면 방향 바꾸기
        if (time == nTurn.first)
        {
            TurnDirection(dir, nTurn.second);
            if (!q.empty())
            {
                nTurn = q.front();
                q.pop();
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y; // 행, 열
        cin >> x >> y;
        map[x][y] = APPLE; // x행 y열에 사과
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int x; // x 초에
        char c; // c 방향으로 (L은 왼쪽, D는 오른쪽)
        cin >> x >> c;
        q.push({ x, c });
    }
    cout << GameEndAt();
    return 0;
}