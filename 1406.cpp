#include <bits/stdc++.h>
using namespace std;

list<char> l;
list<char>::iterator it;
string str;
int M;
char option;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;
    for (auto c : str)
        l.push_back(c);

    cin >> M;
    it = l.end();
    for (int i = 0; i < M; i++)
    {
        cin >> option;
        switch (option)
        {
        case 'L': // 커서를 왼쪽으로 이동
            if (it != l.begin()) it--;
            break;
        case 'D': // 커서를 오른쪽으로 이동
            if (it != l.end()) it++;
            break;
        case 'B': // 왼쪽의 문자를 삭제
            if (it != l.begin())
            {
                it--;
                it = l.erase(it);
            }
            break;
        case 'P': // 왼쪽에 c를 삽입
        {
            char c;
            cin >> c;
            l.insert(it, c);
        }
        }
    }
    for (auto c : l)
        cout << c;
    return 0;
}