#include <iostream>
#include <algorithm>
using namespace std;

int map[1001][1001];
int dp[1001][1001];
int n, m;
int mx;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string ipt;
		cin >> ipt;
		for (int j = 0; j < m; j++)
			map[i][j] = ipt[j] - '0';
	}
	
	for (int j = 0; j < m; j++)
		dp[0][j] = map[0][j];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = map[i][0];
		for (int j = 1; j < m; j++)
		{
			if (map[i][j] == 1)
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
		}
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mx = max(mx, dp[i][j]);
	cout << mx * mx;
	return 0;
}