#include <bits/stdc++.h>
using namespace std;

int N;
int perfo[51][10];
vector<int> seq;
int mx;

int getScore() {
    int base[4] = {0, };
    int outCnt = 0;
    int score = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        fill(base, base + 4, 0);
        outCnt = 0;
        while (outCnt < 3) { // 3아웃이면 다음 이닝으로
            if (perfo[i][seq[cur]] == 0) // 이번 타자가 아웃되면
                outCnt++; // 아웃카운트 + 1
            else { // 이번 타자가 안타, 2루타, 3루타, 홈런을 쳤다면
                // 원래 출루 해있었던 사람들 처리
                for (int j = 3; j > 0; j--) {
                    if (base[j] != 0) { // 1, 2, 3루의 사람들을 옮기는데
                        base[j] = 0;
                        if (j + perfo[i][seq[cur]] > 3) // 이번 타구로 홈까지 갈 수 있으면 점수 추가
                            score++;
                        else // 아니라면 n루만큼 이동
                            base[j + perfo[i][seq[cur]]] = 1;
                    }
                }
                // 지금 타자 처리
                if (perfo[i][seq[cur]] == 4) // 이번 타구가 홈런이었다면
                    score++; // 점수 추가
                else // 홈런이 아니었다면
                    base[perfo[i][seq[cur]]] = 1; // n루에 타자 배치
            }
            cur = (cur + 1) % 9; // 다음 타자
        }
    }
    return score; // 경기가 끝난 후 누적 점수 반환
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++)
            cin >> perfo[i][j];
    }
    vector<int> tmp = {1, 2, 3, 4, 5, 6, 7, 8};
    do {
        seq = tmp;
        seq.insert(seq.begin() + 3, 0);
        mx = max(mx, getScore());
    } while (next_permutation(tmp.begin(), tmp.end()));
    cout << mx;
    return 0;
}