#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1000001]; // 부모 노드의 번호를 저장
int depth[1000001]; // 트리의 높이를 저장

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]); // 경로의 모든 노드들의 부모 노드를 루트 노드로 설정
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    // 이미 같은 트리에 속하는 것이므로 함수 종료
    if (x == y) return;
    // 높이가 더 낮은 트리를 더 높은 트리에 붙인다
    if (depth[x] > depth[y])
        swap(x, y);
    parent[x] = y;
    if (depth[x] == depth[y])
        depth[x]++;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        depth[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) // 합치기
            merge(a, b);
        else // 같은 집합에 속하는지 확인
            cout << (find(a) == find(b) ? "YES\n" : "NO\n");
    }
    return 0;
}