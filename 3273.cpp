#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int a[1000001] = {0, };
    int x;
    int cnt = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a_i; cin >> a_i;
        a[a_i] = 1;
    }

    cin >> x;
    for (int i = 1; i < static_cast<double>(x) / 2; i++)
    {
        if (a[i] && a[x - i])
            cnt++;
    }   
    cout << cnt;
    return 0;
}