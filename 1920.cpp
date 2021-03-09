#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int, int> A;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A[num] = 1;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num; 
        cin >> num;
        cout << A[num] << '\n';
    }
    return 0;
}