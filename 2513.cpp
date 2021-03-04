#include <bits/stdc++.h>
#define P first
#define ST second
using namespace std;

int N, K, S; // N: 아파트 단지의 수, K: 통학버스 정원, S: 학교 위치
deque<pair<int, int>> ap;
int res;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K >> S;
    for (int i = 0; i < N; i++) {
        int p, s;
        cin >> p >> s;
        ap.push_back({p, s});
    }
    sort(ap.begin(), ap.end());
    while (!ap.empty()) {
        if (ap.front().P < S) { // 학교 기준 왼쪽의 아이들을 태운다.
            res += (S - ap.front().P) * 2;
            int rem = K;
            while (rem > 0 && !ap.empty() && ap.front().P < S) {
                if (rem >= ap.front().ST) {
                    rem -= ap.front().ST;
                    ap.pop_front();
                }
                else {
                    ap.front().ST -= rem;
                    rem = 0;
                }
            }
        }
        else { // 학교 기준 오른쪽의 아이들을 태운다
            res += (ap.back().P - S) * 2;
            int rem = K;
            while (rem > 0 && !ap.empty() && ap.back().P > S) {
                if (rem >= ap.back().ST) {
                    rem -= ap.back().ST;
                    ap.pop_back();
                }
                else {
                    ap.back().ST -= rem;
                    rem = 0;
                }
            }
        }
    }
    cout << res;
    return 0;
}