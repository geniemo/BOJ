#include <iostream>
#include <algorithm>
using namespace std;

string add(string n1, string n2) {
    string res;
    int sum = 0;
    while (!n1.empty() || !n2.empty() || sum != 0) {
        if (!n1.empty()) {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty()) {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        res += sum % 10 + '0';
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(void) {
    string a, b;
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}