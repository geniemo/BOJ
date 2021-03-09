#include <iostream>
using namespace std;

int N, M;
int arr[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[num] = 1;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << arr[num] << '\n';
    }
    return 0;
}