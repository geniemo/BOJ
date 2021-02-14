#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int seq[100000];
int l, r;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> seq[i];
    int sum = seq[0];
    int mn = 100001;
    while (l <= r && r < N) {
        if (sum < S)
            sum += seq[++r];
        else if (sum == S) {
            mn = min(mn, r - l + 1);
            sum += seq[++r];
        }
        else { // sum > S
            mn = min(mn, r - l + 1);
            sum -= seq[l++];
        }
    }
    cout << (mn == 100001 ? 0 : mn);
    return 0;
}