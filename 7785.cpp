#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <functional>
using namespace std;

int n;
string name, act;
map<string, int, greater<string>> empl;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> act;
        if (act == "enter")
            empl.insert({name, 1});
        else
            empl.erase(name);
    }

    for (pair<string, int> elem : empl)
        cout << elem.first << '\n';
    return 0;
}