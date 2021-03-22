#include <bits/stdc++.h>
using namespace std;

int N;
int lt[11];
int row[10];

void setPos(int h) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (row[i] == 0) {
            if (cnt == lt[h]) {
                row[i] = h;
                break;
            }
            cnt++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> lt[i];
    }
    for (int i = 1; i <= N; i++) {
        setPos(i);
    }
    for (int i = 0; i < N; i++)
        cout << row[i] << ' ';
    return 0;
}