#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, K;
set<int> mt;
vector<int> order(1);
int cnt;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    cin >> order[0];
    for (int i = 1; i < K; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp != order[i - 1])
            order.push_back(tmp);
    }

    for (int i = 0; i < order.size(); i++)
    {
        if (mt.find(order[i]) != mt.end()) // 이미 끼워져 있다면 다음 순서 확인
            continue;
        else if (mt.size() < N) // 멀티탭이 남아 있다면
            mt.insert(order[i]);
        else // 멀티탭이 꽉 찼을 때
        {
            // 하나를 빼야 한다면 이후 한번도 쓰이지 않는 것을 빼고, 그런 것이 없다면 가장 나중에 다시 쓰이는 것을 뺀다.
            int mx = -1;
            int elem = -1;
            for (auto elem_ : mt)
            {
                int tmp;
                for (tmp = i + 1; tmp < order.size(); tmp++)
                {
                    if (order[tmp] == elem_)
                        break;
                }
                if (tmp > mx)
                {
                    mx = tmp;
                    elem = elem_;
                }
            }
            mt.erase(elem);
            mt.insert(order[i]);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}