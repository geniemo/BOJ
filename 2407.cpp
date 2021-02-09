#include <bits/stdc++.h>
using namespace std;

string dp[101][101];

string add(string num1, string num2) {
    string res;
    int sum = 0;
    while (!num1.empty() || !num2.empty() || sum != 0) {
        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        res += sum % 10 + '0';
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string comb(int n, int m) {
    if (n == 0 || n == m)
        return "1";
    if (dp[n][m] != "")
        return dp[n][m];
    return dp[n][m] = add(comb(n - 1, m - 1), comb(n - 1, m));
}

int main(void) {
    int n, m;
    cin >> n >> m;
    cout << comb(n, m);
    return 0;
}