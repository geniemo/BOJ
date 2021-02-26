#include <bits/stdc++.h>
using namespace std;

string str;
int res;
stack<int> s;
string tmp;
int mul = 1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> str;
	for (char c : str) {
		if (c == '(') {
			res += mul * (tmp.length() - 1);
			s.push(tmp.back() - '0');
			mul *= tmp.back() - '0';
			tmp.clear();
		}
		else if (c == ')') {
			res += mul * tmp.length();
			mul /= s.top();
			s.pop();
			tmp.clear();
		}
		else { // c is digit
			tmp += c;
		}
	}
	res += tmp.length();
	cout << res;
	return 0;
}
