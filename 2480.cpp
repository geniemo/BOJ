#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dice[3];
    int n;
    int cnt = 0;

    cin >> dice[0] >> dice[1] >> dice[2];
    for (int i = 0; i < 3; i++)
    {
            int cnt_ = 0;
            for (int j = 0; j < 3; j++)
                    cnt_ = (dice[j] == dice[i]) ? cnt_ + 1 : cnt_;
            if (cnt_ > cnt)
            {
                    n = dice[i];
                    cnt = cnt_;
            }
    }
    
    switch (cnt)
    {
    case 3:
        cout << 10000 + n * 1000;
        break;
    case 2:
        cout << 1000 + n * 100;
        break;
    case 1:
        cout << 100 * (*max_element(dice, dice + 3));
    }
    return 0;
}