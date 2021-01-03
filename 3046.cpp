#include <iostream>
using namespace std;

int main(void)
{
    int R1, S;
    cin >> R1 >> S; // S is (R1 + R2) / 2
    cout << 2*S - R1; // R2 is 2*S - R1
    return 0;
}