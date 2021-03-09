#include <bits/stdc++.h>
using namespace std;

int N, K;
deque<int> dq;
int v[4243];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        dq.push_back(i + 1);
    for (int i = 1; i <= N; i++) {
        if (N - i <= K) { // i번째 사람에게 쪽지를 줘서 만들 수 있는 커플의 수보다 필요한 커플 수가 많다면
            v[i] = dq.back(); // 남은 쪽지번호 중 가장 큰 번호를 줘서 N - i쌍의 커플을 만든다.
            dq.pop_back();
            K -= N - i; // 남은 커플 수를 뺀다
        }
        else { // N - i > K: 만들 수 있는 커플의 수보다 필요한 커플 수가 적다면
            v[i] = dq.front(); // 남은 쪽지 번호 중 가장 작은 번호를 줘서 커플을 만들지 않는다.
            dq.pop_front();
        }
    }
    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
    return 0;
}