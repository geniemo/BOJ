#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int five = n / 5; // 5원짜리 동전의 최대 개수
    int two = 0;
    while (five >= 0)
    {
        if ((n - (five * 5)) % 2 == 0) // 5원짜리를 빼고 남은 돈을 2원으로 지급 가능하다면
        {
            two = (n - (five * 5)) / 2; // 남은 돈을 2원짜리 동전으로 환산
            break;
        }
        five--;
    }
    if (five == -1)
        cout << -1;
    else
        cout << five + two;
    return 0;
}