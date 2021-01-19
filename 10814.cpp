#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    multimap<int, string> m;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        m.insert(pair<int, string>(age, name));
    }

    for (multimap<int, string>::iterator it = m.begin(); it != m.end(); it++)
        cout << it->first << ' ' << it->second << '\n';
    return 0;
}