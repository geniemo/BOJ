#include <iostream>
using namespace std;

long long side[2] = {0, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        long long next = side[0] + side[1];
        side[0] = side[1];
        side[1] = next;
    }
    cout << 4 * side[1] + 2 * side[0];
    return 0;
}