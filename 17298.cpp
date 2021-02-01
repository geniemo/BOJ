#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int seq[1000000];
int nge[1000000];
stack<int> s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    fill(nge, nge + N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
        while (!s.empty() && seq[i] > seq[s.top()])
        {
            nge[s.top()] = seq[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < N; i++)
        cout << nge[i] << ' ';
    return 0;
}