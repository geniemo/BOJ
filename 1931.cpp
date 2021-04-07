#include <bits/stdc++.h>
using namespace std;

int N;
int st_org[100005];
pair<int, int> en[100005];
int cnt;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first)
        return st_org[a.second] < st_org[b.second];
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> st_org[i] >> en[i].first;
        en[i].second = i;
    }
    sort(en, en + N, cmp); // 회의가 끝난 시간 기준 오름차순 정렬, 끝난시간이 같다면 시작한 시간 기준 오름차순 정렬
    int endTime = -1; // 저번 회의가 끝난 시간
    for (int i = 0; i < N; i++) {
        // 저번 회의가 끝난 시간이 en[i]의 시작시간보다 이르다면 카운트
        if (endTime <= st_org[en[i].second]) {
            cnt++;
            endTime = en[i].first;
        }
    }
    cout << cnt;
    return 0;
}