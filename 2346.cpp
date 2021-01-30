#include <iostream>
#include <utility>
#define LOC first
#define D second
using namespace std;

int N;
int balloon[1001];
int seq[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> balloon[i];

    pair<int, int> cur = { 1, balloon[1] };
    for (int i = 1; i < N; i++)
    {
        // 풍선을 터뜨린다
        balloon[cur.LOC] = 0;
        seq[i] = cur.LOC;

        // 다음 위치로 이동
        int loc = cur.LOC;
        if (cur.D > 0)
        {
            for (int j = 0; j < cur.D; j++)
            {
                while (1)
                {
                    loc++;
                    if (loc > N) loc = 0;
                    if (balloon[loc] != 0)
                        break;
                }
            }
        }
        else
        {
            for (int j = cur.D; j < 0; j++)
            {
                while (1)
                {
                    loc--;
                    if (loc <= 0) loc = N;
                    if (balloon[loc] != 0)
                        break;
                }
            }
        }
        cur = { loc, balloon[loc] };
    }
    balloon[cur.LOC] = 0;
    seq[N] = cur.LOC;

    for (int i = 1; i <= N; i++)
        cout << seq[i] << ' ';
    return 0;
}