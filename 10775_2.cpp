#include <iostream>
using namespace std;

int G, P;
int parent[100005];
int cnt;

int find(int x)
{
    if (parent[x] == x)
        return x;
    else // 경로 압축. 만나면서 만나는 모든 값의 부모 노드를 root로 만든다
        return parent[x] = find(parent[x]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> G >> P;
    for (int i = 0; i <= G; i++)
        parent[i] = i;
    for (int i = 0; i < P; i++)
    {
        int seq;
        cin >> seq;
        int f = find(seq);
        if (f == 0) break;
        parent[f] = f - 1;
        cnt++;
    }
    cout << cnt;
    return 0;
}