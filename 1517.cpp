#include <bits/stdc++.h>
using namespace std;

int N;
int arr[500005];
int tmp[500005];
long long res;

void merge(int l, int m, int r) {
    long long cnt = 0;
    int idx = l;
    int i1 = l, i2 = m + 1;
    while (idx <= r) {
        // 둘중 하나를 모두 배치했을 때, 남은 하나를 마저 배치해줘야 한다.
        if (i1 > m) { // l ~ m 배열을 모두 배치했다면
            tmp[idx++] = arr[i2++];
        }
        else if (i2 > r) { // m + 1 ~ r 배열을 모두 배치했다면
            tmp[idx++] = arr[i1++];
            res += cnt;
        }
        // 둘 다 배치가 아직 안됐을 경우
        else if (arr[i1] <= arr[i2]) { // l ~ m 배열의 다음 원소가 더 작다면 먼저 배치
            tmp[idx++] = arr[i1++];
            res += cnt;
        }
        else { // m + 1 ~ r 배열의 다음 원소가 더 작다면 먼저 배치
            tmp[idx++] = arr[i2++];
            cnt++;
        }
    }
    for (int i = l; i <= r; i++)
        arr[i] = tmp[i];
}

void mergeSort(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    mergeSort(0, N - 1);
    cout << res;
    return 0;
}