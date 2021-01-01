#include <iostream>
using namespace std;

// check how many blocks have to be painted newly
int NewPaint(const char arr[][50], const int &i, const int &j)
{
    // start with white
    int cntW = 0;
    char color = 'B';
    for (int idx1 = i; idx1 < i + 8; idx1++)
    {
        color = (color == 'B') ? 'W' : 'B'; // next block color should be equal with color
        for (int idx2 = j; idx2 < j + 8; idx2++)
        {
            cntW = (arr[idx1][idx2] == color) ? cntW : cntW + 1; // if arr[idx1][idx2] is not equal with color, we should re-paint this block
            color = (color == 'B') ? 'W' : 'B'; // next block color should be equal with color
        }
    }

    // start with black
    int cntB = 0;
    color = 'W';
    for (int idx1 = i; idx1 < i + 8; idx1++)
    {
        color = (color == 'B') ? 'W' : 'B'; // next block color should be equal with color
        for (int idx2 = j; idx2 < j + 8; idx2++)
        {
            cntB = (arr[idx1][idx2] == color) ? cntB : cntB + 1; // if arr[idx1][idx2] is not equal with color, we should re-paint this block
            color = (color == 'B') ? 'W' : 'B'; // next block color should be equal with color
        }
    }

    return (cntW < cntB) ? cntW : cntB;
}

// check all cases
void ChessSelect(const char arr[][50], const int &n, const int &m)
{
    int min = 2501; // min can't be bigger than 2500
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
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %d", &arr[i][j]);

    ChessSelect(arr, n, m);
    
    return 0;
}