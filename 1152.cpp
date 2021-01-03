#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void)
{
    string str;
    int cnt = 0;
    getline(cin, str);

    if (isalpha(str[0])) cnt += 1; // cal first word seperately
    for (int i = 0; i < str.length(); i++) // the word after first word is located behind of space
        if (isblank(str[i]) && isalpha(str[i + 1]))
            cnt += 1;
    
    printf("%d", cnt);
    return 0;
}