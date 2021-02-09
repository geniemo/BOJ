#include <bits/stdc++.h>
using namespace std;

int visited[201][201];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int i = 0; i < 201; i++)
            fill(visited[i], visited[i] + 201, 0);
        string w1, w2, w3;
        cin >> w1 >> w2 >> w3;
        int w1sz = w1.size(), w2sz = w2.size(), w3sz = w3.size();
        bool is_able = false;
        queue<pair<int, int>> q;
        visited[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            int j = q.front().first;
            int k = q.front().second;
            q.pop();

            if (j == w1sz && k == w2sz && j + k == w3sz) {
                is_able = true;
                break;
            }

            if (j != w1sz && w1[j] == w3[j + k] && visited[j + 1][k] == 0) {
                visited[j + 1][k] = 1;
                q.push({j + 1, k});
            }
            if (k != w2sz && w2[k] == w3[j + k] && visited[j][k + 1] == 0) {
                visited[j][k + 1] = 1;
                q.push({j, k + 1});
            }
        }
        cout << "Data set " << i << ": " << (is_able ? "yes" : "no") << '\n';
    }
    return 0;
}