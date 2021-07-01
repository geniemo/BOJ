#include <iostream>
using namespace std;
int cost;
int cnt = 0;
void c(int n) {
    cnt += cost / n; cost %= n;
}
int main(void) {
    cin >> cost;
    cost = 1000 - cost;
    c(500); c(100); c(50); c(10); c(5); c(1);
    cout << cnt;
    return 0;
}