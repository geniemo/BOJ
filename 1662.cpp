#include <bits/stdc++.h>
using namespace std;

string str;
int res;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> str;
	string tmp;
	stack<int> s;
	for (char c : str) {
		if (c == '(') {
			if (!tmp.empty()) {
				s.push(stoi(tmp));
				tmp.clear();
			}
			s.push(c);
		}
		else if (c == ')') {
			if (s.top() == '(') {
				s.pop();
				s.top() = s.top() * tmp.length();
				tmp.clear();
			}
			else { // s.top() is digit
				int t = s.top() + tmp.length();
				s.pop();
				s.pop();
				tmp.clear();
				while (!s.empty() && s.top() != '(') {
					t *= s.top();
					s.pop();
				}
				if (s.empty())
					res += t;
				else
					s.push(t);
			}
		}
		else { // c is digit
			tmp += c;
		}
	}
	while (!s.empty())
		res += s.top();
	cout << res;
	return 0;
}
