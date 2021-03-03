#include <bits/stdc++.h>
using namespace std;

int sieve[10000];
int depth[10000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= 9999; i++) {
        if (sieve[i] == 0) {
            for (int j = i * i; j <= 9999; j += i)
                sieve[j]++;
        }
    }

    int T;
    cin >> T;
    for (int T_ = 0; T_ < T; T_++) {
        fill(depth, depth + 10000, -1);
        string org, dst;
        cin >> org >> dst;
        queue<string> q;
        depth[stoi(org)] = 0;
        q.push(org);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur == dst)
                break;
            for (int i = 0; i < 4; i++) {
                string tmp = cur;
                for (int j = (i == 0) ? '1' : '0'; j <= '9'; j++) {
                    tmp[i] = j;
                    int tmp_i = stoi(tmp);
                    if (sieve[tmp_i] == 0 && depth[tmp_i] == -1) {
                        depth[tmp_i] = depth[stoi(cur)] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
        if (depth[stoi(dst)] == -1)
            cout << "Impossible\n";
        else
            cout << depth[stoi(dst)] << '\n';
    } 
    return 0;
}