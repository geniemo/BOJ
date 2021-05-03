#include <bits/stdc++.h>
using namespace std;

int T;
string str;

bool is_palindrome(int l, int r) {
    while (l < r) {
        if (str[l++] != str[r--])
            return false;
    }
    return true;
}

int sol() {
    int l = 0, r = str.length() - 1;
    while (l < r) {
        if (str[l] != str[r]) {
            if (is_palindrome(l, r - 1) || is_palindrome(l + 1, r))
                return 1;
            return 2;
        }
        l++, r--;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;
        cout << sol() << "\n";
    }
    return 0;
}