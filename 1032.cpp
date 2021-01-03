#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string pattern;
    string file;
    int N;
    cin >> N;
    cin >> file;
    pattern = file; // initial state of pattern
    for (int i = 0; i < N - 1; i++)
    {
        cin >> file;
        for (int j = 0; j < pattern.length(); j++) 
        {
            if (pattern[j] != file[j]) // change different part of pattern as '?'
                pattern[j] = '?';
        }
    }
    cout << pattern;
    return 0;
}