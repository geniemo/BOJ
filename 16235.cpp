#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[11][11];
int field[11][11];
deque<int> tr[11][11];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        fill(field[i] + 1, field[i] + N + 1, 5); // 밭의 초기 양분
        for (int j = 1; j <= N; j++)
            cin >> A[i][j]; // 겨울마다 로봇이 각 칸에 더해줄 양분
    }
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tr[x][y].push_back(z); // (x, y)에 나이가 z인 나무 심기
    }

    for (int y = 0; y < K; y++) {
        // 봄, 여름: 나무들이 양분을 흡수, 양분이 부족하면 죽어서 양분으로 변화
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int food = 0;
                int trCnt = tr[i][j].size();
                for (int k = 0; k < trCnt; k++) {
                    int tmp = tr[i][j].front(); tr[i][j].pop_front();
                    if (field[i][j] >= tmp) { // 양분이 충분하다면 양분 흡수
                        field[i][j] -= tmp;
                        tr[i][j].push_back(tmp + 1);
                    }
                    else // 양분을 먹지 못하는 나무는 양분으로 변화
                        food += tmp / 2;
                }
                sort(tr[i][j].begin(), tr[i][j].end());
                field[i][j] += food;
            }
        }
        // 가을: 나이가 5의 배수인 나무와 인접한 8개의 칸에 나이가 1인 나무 추가
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int t : tr[i][j]) {
                    if (t % 5 == 0) {
                        for (int k = 0; k < 8; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (1 <= nx && nx <= N && 1 <= ny && ny <= N)
                                tr[nx][ny].push_front(1);
                        }
                    }
                }
            }
        }
        // 겨울: 각 칸에 양분 지급        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                field[i][j] += A[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            res += tr[i][j].size();
    }
    cout << res;
    return 0;
}