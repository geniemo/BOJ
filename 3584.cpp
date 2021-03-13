#include <bits/stdc++.h>
using namespace std;

int parent[10001];

int getDepth(int a) {
    int depth = 0;
    int cur = parent[a];
    while (cur != 0) {
        cur = parent[cur];
        depth++;
    }
    return depth;
}

int getCoAnc(int a, int b) {
    int a_depth = getDepth(a);
    int b_depth = getDepth(b);
    while (1) {
        if (a_depth == b_depth) { // 두 노드의 깊이가 같다면
            if (a == b) // 최소 공통 조상을 찾았다면 반환!(어떤 노드의 부모에는 자기 자신도 포함된다.)
                return a;
            // 찾지 못했다면 a, b를 각각의 부모로 바꾸어준다.
            a = parent[a];
            b = parent[b];
        }
        else { // 두 노드의 깊이가 다르다면
            // a가 더 깊이 있다면 a를 a의 부모로 바꾸고 depth 감소
            if (a_depth > b_depth) {
                a = parent[a];
                a_depth--;
            }
            // b가 더 깊이 있다면 b를 b의 부모로 바꾸고 depth 감소
            else { // a_depth < b_depth
                b = parent[b];
                b_depth--;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int T_ = 0; T_ < T; T_++) {
        memset(parent, 0, sizeof(parent));
        int N, A, B;
        cin >> N;
        for (int i = 0; i < N - 1; i++) {
            cin >> A >> B;
            parent[B] = A;
        }
        cin >> A >> B;
        cout << getCoAnc(A, B) << '\n';
    }
    return 0;
}