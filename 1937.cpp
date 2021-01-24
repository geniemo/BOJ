#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#define PAIR pair<int, pair<int, int>>
#define BAM first
#define LOC second
#define X first
#define Y second
using namespace std;

int n, day;
int map[500][500];
int dp[500][500];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 오, 왼, 아, 위

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<PAIR> bam(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            bam[i * n + j] = {map[i][j], {i, j}};
        }
    }
    sort(bam.begin(), bam.end(), greater<PAIR>()); // 대나무가 많은 숲부터 처리하기 위해 내림차순 정렬

    for (int i = 0; i < n * n; i++)
    {
        PAIR cur = bam[i];
        int tmp = 0;
        for (int j = 0; j < 4; j++)
        {
            int nx = cur.LOC.X + dx[j];
            int ny = cur.LOC.Y + dy[j];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (map[nx][ny] > cur.BAM) // 주변에 지금 위치보다 더 많은 대나무가 있는 곳이 있다면
                    tmp = max(dp[nx][ny], tmp); // 그 방향으로 가는 것이 현명한지 판단
            }
        }
        dp[cur.LOC.X][cur.LOC.Y] = 1 + tmp;
        day = max(dp[cur.LOC.X][cur.LOC.Y], day);
    }
    cout << day;
    
    return 0;
}