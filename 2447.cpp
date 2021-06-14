#include <bits/stdc++.h>
using namespace std;

int N;

void print(int x, int y, int len) {
    if ((x / len) % 3 == 1 && (y / len) % 3 == 1) {
        cout << ' ';
    }
    else if (len / 3 == 0) {
        cout << "*";
    }
    else {
        print(x, y, len / 3);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            print(i, j, N);
        cout << "\n";
    }
    return 0;
}