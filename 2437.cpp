#include <iostream>
#include <algorithm>
using namespace std;

int N;
int w[1000];
int sum;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> w[i];
    sort(w, w + N);

    for (int i = 0; i < N; i++)
    {
        if (w[i] > sum + 1) // w[i] <= sum + 1 이라면 1 ~ sum + w[i] 까지 나타낼 수 있다
            break;
        sum += w[i];
    }
    cout << sum + 1;
    return 0;
}