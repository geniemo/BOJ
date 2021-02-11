#include <bits/stdc++.h>
using namespace std;

int k;
char comp[9];
bool comb[10];

bool IsRight(string seq) {
    for (int i = 0; i < k; i++) {
        switch (comp[i]) {
            case '<':
                if (seq[i] > seq[i + 1])
                    return false;
                break;
            case '>':
                if (seq[i] < seq[i + 1])
                    return false;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> comp[i];
        comb[9 - i] = true;
    }
    comb[9 - k] = true;

    string mx, mn;
    long long mx_ = -1, mn_ = 0x7f7f7f7f7f7f7f7f;
    do {
        // 숫자 k + 1개 고르기
        string seq;
        for (int i = 0; i < 10; i++) {
            if (comb[i])
                seq += (i + '0');
        }
        // 조건에 맞는 숫자라면 mx, mn 값 갱신
        do {
            if (IsRight(seq)) {
                long long tmp = stoll(seq);
                if (tmp > mx_) {
                    mx = seq;
                    mx_ = tmp;
                }
                if (tmp < mn_) {
                    mn = seq;
                    mn_ = tmp;
                }
            }
        }
        while (next_permutation(seq.begin(), seq.end()));
    } while (next_permutation(comb, comb + 10));
    cout << mx << '\n' << mn;
    return 0;
}