#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string name, act;
unordered_map<string, int> empl;
vector<string> sortedEmpl;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> act;
        if (act == "enter")
            empl.insert({name, 1});
        else
            empl.erase(name);
    }

    for (pair<string, int> elem : empl)
        sortedEmpl.push_back(elem.first);
    sort(sortedEmpl.begin(), sortedEmpl.end(), greater<string>()); // 사전 역순
    for (string s : sortedEmpl)
        cout << s << '\n';
    return 0;
}