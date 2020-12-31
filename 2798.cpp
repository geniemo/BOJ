#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    int largest = 0;
    cin >> n >> m;

    int *arr = new int[n];
    int idx[3] = {0, 1, 2};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (1)
    {
        int sum = arr[idx[0]] + arr[idx[1]] + arr[idx[2]];
        largest = (sum > largest && sum <= m) ? sum : largest;
        if (idx[2] != n - 1)
            idx[2]++;
        else if (idx[1] != n - 2)
        {
            idx[1]++;
            idx[2] = idx[1] + 1;
        }
        else if (idx[0] != n - 3)
        {
            idx[0]++;
            idx[1] = idx[0] + 1;
            idx[2] = idx[1] + 1;
        }
        else
            break;
    }
    cout << largest;
    return 0;
}

