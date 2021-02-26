#include <bits/stdc++.h>
using namespace std;

string str;
int res;
stack<int> s;
string tmp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	s.push(1);
	for (char c : str) {
		if (c == '(') {
			res += s.top() * (tmp.length() - 1);
			s.push(s.top() * (tmp.back() - '0'));
			tmp.clear();
		}
		else if (c == ')') {
			res += s.top() * tmp.length();
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
