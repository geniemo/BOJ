#include <iostream>
using namespace std;

int N, K;
int coin[10];
int cnt;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = N - 1; i >= 0; i--)
        cin >> coin[i]; // 내림차순으로 저장
    
    // 금액이 큰것부터 처리
    for (int i = 0; i < N; i++)
    {
        if (coin[i] > K) continue; // 동전의 금액이 남은 금액보다 크다면

        cnt += (K / coin[i]);
        K %= coin[i];
        if (K == 0) break; // 원하는 돈을 만들었다면 break
    }
    cout << cnt;
    return 0;
}