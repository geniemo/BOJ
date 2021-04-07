#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define ST      second
#define EN      first
using namespace std;

int N;
PAIR t[100005];
int cnt;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t[i].ST >> t[i].EN;
    }
    sort(t, t + N); // 회의가 끝난 시간 기준 오름차순 정렬, 끝난시간이 같다면 시작한 시간 기준 오름차순 정렬
    int endTime = -1; // 저번 회의가 끝난 시간
    for (int i = 0; i < N; i++) {
        // 저번 회의가 끝난 시간이 t[i]의 시작시간보다 이르다면 카운트
        if (endTime <= t[i].ST) {
            cnt++;
            endTime = t[i].EN;
        }
    }
    cout << cnt;
    return 0;
}