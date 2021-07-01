#include <bits/stdc++.h>
using namespace std;

int N;
int arr[500005];
int sum;
int cnt[8005];

int avg() {
    return round((double)sum / N);
}

int mid() {
    return arr[N / 2];
}

int mode() {
    int mx_idx = max_element(cnt, cnt + 8005) - cnt;
    for (int i = mx_idx + 1; i <= 8000; i++) {
        if (cnt[i] == cnt[mx_idx]) {
            mx_idx = i;
            break;
        }
    }
    return mx_idx - 4000;
}

int range() {
    return *max_element(arr, arr + N) - *min_element(arr, arr + N);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i] + 4000]++;
    }
    sort(arr, arr + N);
    cout << avg() << "\n" << mid() << "\n" << mode() << "\n" << range();
    return 0;
}