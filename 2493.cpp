#include <iostream>
#include <stack>
using namespace std;

int N;
int tower[500001];
stack<int> s;
int res[500001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> tower[i];
    
    for (int i = N; i >= 1; i--)
    {
        while (!s.empty() && tower[i] > tower[s.top()])
        {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';
    return 0;   
}