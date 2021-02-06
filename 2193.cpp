#include <iostream>
using namespace std;

// same with N+1-th fibo
long long pinary(int N)
{
    long long pin[2] = {0, 1}; // fibo 1 and fibo 2
    
    for (int i = 3; i <= N + 1; i++)
    {
        long long next = pin[0] + pin[1];
        pin[0] = pin[1];
        pin[1] = next;
    }
    return pin[1];
}

int main(void)
{
    int N;
    cin >> N;
    cout << pinary(N);
    return 0;
}