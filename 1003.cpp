#include <iostream>
#include <utility>
using namespace std;

int main(void)
{
    pair<int, int> cnt[41];
    cnt[0] = {1, 0};
    cnt[1] = {0, 1};
    for (int i = 2; i <= 40; i++)
        cnt[i] = {cnt[i - 1].first + cnt[i - 2].first, cnt[i - 1].second + cnt[i - 2].second};

    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf(" %d", &N);
        printf("%d %d\n", cnt[N].first, cnt[N].second);
    }
    return 0;
}