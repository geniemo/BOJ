#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#define PAIRPQ priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define INTPQ priority_queue<int, vector<int>, greater<int>>
using namespace std;

int N;
int com[100000];
int cnt;

INTPQ pq; // 시작과 종료가 시행될 시간을 시작, 종료를 구분하지 않고 오름차순으로 저장
PAIRPQ stpq; // 시작과 종료시간을 시작시간 오름차순으로 저장
PAIRPQ enpq; // 종료시간과 종료할 컴퓨터 번호를 종료시간 오름차순으로 저장
INTPQ rempq; // 종료되어있어 비어있는 컴퓨터를 컴퓨터번호 오름차순으로 저장

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int st, en;
        cin >> st >> en;
        pq.push(st); pq.push(en);
        stpq.push({st, en});
    }

    while (1)
    {
        if (stpq.empty() && enpq.empty()) // 모든 사람의 컴퓨터 이용이 끝남
        {
            cout << cnt << '\n';
            for (int i = 0; i < cnt; i++)
                cout << com[i] << ' ';
            break;
        }

        int time = pq.top(); pq.pop();
        if (!stpq.empty() && time == stpq.top().first) // 컴퓨터 시작시간이라면
        {
            pair<int, int> st = stpq.top(); stpq.pop();
            if (rempq.empty()) // 앞의 컴퓨터가 모두 다 사용중이라면
            {
                enpq.push({st.second , cnt});
                com[cnt++] += 1; // 마지막 컴퓨터의 다음 컴퓨터를 사용
            }
            else // 중간에 사용중이지 않은 컴퓨터가 있다면
            {
                enpq.push({st.second, rempq.top()});
                com[rempq.top()] += 1;
                rempq.pop();
            }
        }
        else // 컴퓨터 종료시간이라면
        {
            rempq.push(enpq.top().second);
            enpq.pop();
        }
    }
    return 0;
}