#include <iostream>
#include <utility>
using namespace std;

int main(void)
{
    pair<int, int> cnt[static_cast<const int>(41)];
    cnt[0] = {1, 0};
    cnt[1] = {0, 1};
    for (int j = 2; j <= 40; j++)
        cnt[j] = {cnt[j - 1].first + cnt[j - 2].first, cnt[j - 1].second + cnt[j - 2].second};

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