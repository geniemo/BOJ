#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int price[16][16];
int dp[1 << 16]; // 인덱스의 각 자릿수를 하나의 비트로 볼 수 있도록
string stateStr;
int state;
int least;
int res = 0x7f7f7f7f;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> price[i][j];
    cin >> stateStr;
    cin >> least;
    for (int i = N - 1; i >= 0; i--)
        state = (state << 1) | (stateStr[i] == 'Y'); // 비트마스크를 이용해 현재상태를 기록
    fill(dp, dp + (1 << N), 0x7f7f7f7f);
    dp[state] = 0;

    for (int bmask = 1; bmask < (1 << N); bmask++)
    {
        int tmp = bmask;
        vector<int> v;
        // 이번 bmask에서 몇 번째 발전기가 켜져있는지 vector에 모두 기록
        for (int i = 0; i < N; i++)
        {
            if (tmp & 1) v.push_back(i);
            tmp >>= 1;
        }
        int nCnt = v.size(); // 이번 bmask에서 켜져있는 발전기의 수
        for (int i = 0; i < nCnt; i++)
        {
            for (int j = 0; j < nCnt; j++)
            {
                if (i == j) continue;
                int np = dp[bmask ^ (1 << v[i])] + price[v[j]][v[i]]; // 이전 상태에서 v[i]번째 발전기를 고쳐서 지금의 bmask로 될 때 필요한 비용
                dp[bmask] = min(np, dp[bmask]);
            }
        }
        if (nCnt >= least && dp[bmask] < res) // 여태까지 중 최소비용으로 최소 제한을 충족하였다면 
            res = dp[bmask];
    }

    if (least == 0) res = 0;
    if (res == 0x7f7f7f7f) res = -1;
    cout << res;
    return 0;
}