#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <string>
#define ST first
#define EN second
using namespace std;

string ipt;
stack<int> s;
vector<pair<int, int>> pole;
vector<double> laser;
int cnt;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> ipt;
    for (int i = 0; i < ipt.length(); i++)
    {
        if (ipt[i] == '(')
            s.push(i);
        else // ')'
        {
            if (s.top() == i - 1)
                laser.push_back( (i + s.top()) / static_cast<double>(2) );
            else
                pole.push_back({s.top(), i});
            s.pop();
        }
    }

    for (auto pIt = pole.begin(); pIt != pole.end(); pIt++)
    {
        int sep = 1;
        for (auto lIt = laser.begin(); lIt != laser.end(); lIt++)
        {
            if ((*pIt).ST < *lIt && *lIt < (*pIt).EN)
                sep++;
        }
        cnt += sep;
    }
    cout << cnt;
    return 0;
}