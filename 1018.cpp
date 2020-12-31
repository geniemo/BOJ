#include <iostream>
using namespace std;

int NewPaint(const char arr[][50], const int &i, const int &j)
{
    int cntW = 0, cntB = 0;

    char color = 'B';
    for (int idx1 = i; idx1 < i + 8; idx1++)
    {
        color = (color == 'B') ? 'W' : 'B';
        for (int idx2 = j; idx2 < j + 8; idx2++)
        {
            cntW = (arr[idx1][idx2] == color) ? cntW : cntW + 1;
            color = (color == 'B') ? 'W' : 'B';
        }
    }
    
    color = 'W';
    for (int idx1 = i; idx1 < i + 8; idx1++)
    {
        color = (color == 'B') ? 'W' : 'B';
        for (int idx2 = j; idx2 < j + 8; idx2++)
        {
            cntB = (arr[idx1][idx2] == color) ? cntB : cntB + 1;
            color = (color == 'B') ? 'W' : 'B';
        }
    }

    return (cntW < cntB) ? cntW : cntB;
}
void ChessSelect(const char arr[][50], const int &n, const int &m)
{
    int min = 2501;
    for (int i = 0; i <= n - 8; i++)
        for (int j = 0; j <= m - 8; j++)
        {
            int k = NewPaint(arr, i, j);
            min = (k < min) ? k : min;
        }

    cout << min;
}

int main(void)
{
    char arr[50][50];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    ChessSelect(arr, n, m);
    
    return 0;
}