#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int hist[26] = {0, };
    string word;
    cin >> word;
    for (auto i : word)
        hist[i - 'a']++;
    
    for (auto i : hist)
        cout << i << ' ';
    return 0;
}