#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> h(9);
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> h[i];
        sum += h[i];
    }
    
    for (auto i = h.begin(); i < h.end(); i++)
    {
        for (auto j = i + 1; j < h.end(); j++)
        {
            if (sum - *i - *j == 100)
            {
                h.erase(i);
                h.erase(j - 1);
                i = h.end();
                break;
            }
        }
    }

    sort(h.begin(), h.end());
    for (auto i = h.begin(); i < h.end(); i++)
        cout << *i << '\n';
    return 0;
}