#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;
int idx;
int seq[5000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        q.push(i);
    
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        seq[idx++] = q.front();
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < N - 1; i++)
        cout << seq[i] << ", ";
    cout << seq[N - 1] << ">";
    return 0;
}