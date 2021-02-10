#include <bits/stdc++.h>
using namespace std;

int N, M;
int frontCnt[32001]; // i번째 사람보다 앞에 있어야 하는 사람의 수
vector<int> atBack[32001]; // i번째 사람보다 뒤에 있어야 하는 사람의 번호

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int f, b;
        cin >> f >> b;
        atBack[f].push_back(b);
        frontCnt[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (frontCnt[i] == 0) // 앞에 있어야 하는 사람이 아무도 없거나 비교정보가 없다면
            q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i : atBack[cur]) {
            frontCnt[i]--;
            if (frontCnt[i] == 0) // 앞에 있어야 하는 사람이 이미 다 처리된 후라면
                q.push(i);
        }
    }
    return 0;
}