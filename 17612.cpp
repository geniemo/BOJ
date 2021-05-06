#include <bits/stdc++.h>
#define PQ(cmp) priority_queue<ti3, vector<ti3>, cmp>
#define ti3     tuple<int, int, int>
#define ID      get<0>
#define W       get<1>
#define C       get<2>
using namespace std;

// 줄 세울 때
struct cmp_in {
    bool operator()(ti3& a, ti3& b) {
        // 대기시간이 같으면 카운터 번호 낮은 순으로 줄세움
        if (W(a) == W(b)) {
            return C(b) < C(a);
        }
        // 대기시간이 다르면 대기시간이 빠른 순으로 줄세움
        return W(b) < W(a);
    }   
};

// 빠져나올 때
struct cmp_out {
    bool operator()(ti3& a, ti3& b) {
        // 같이 끝난다면 카운터 번호 높은 순으로 빠져나옴
        if (W(a) == W(b)) {
            return C(b) > C(a);
        }
        // 같이 끝나지 않는다면 먼저 끝나는 사람 먼저 나옴
        return W(b) < W(a);
    }
};

int N, k; // 사람 수, 계산대 수
int id;
int w;
long long res;
PQ(cmp_in) pq_in;
PQ(cmp_out) pq_out;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        cin >> id >> w;
        if (i < k) {
            pq_in.push({id, w, i});
            continue;
        }
        ti3 tmp = pq_in.top();
        pq_in.pop();
        pq_in.push({id, W(tmp) + w, C(tmp)});
        pq_out.push(tmp);
    }
    while (!pq_in.empty()) {
        pq_out.push(pq_in.top());
        pq_in.pop();
    }
    long long cnt = 1;
    while (!pq_out.empty()) {
        res += ID(pq_out.top()) * cnt++;
        pq_out.pop();
    }
    cout << res;
    return 0;
}