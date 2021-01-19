#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int row[500];
int col[500];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    int num;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            while (num > 0)
            {
                if (num % 10 == 9)
                {
                    sum++;
                    row[i]++;
                    col[j]++; 
                }
                num /= 10;
            }
        }
    }
    int rowM = *max_element(row, row + n);
    int colM = *max_element(col, col + m);
    sum -= (rowM > colM) ? rowM : colM;
    cout << sum;
    return 0;
}