#include <iostream>
using namespace std;

enum {CABN_WARMN, CABY_WARMN, CABY_WARMY};

// place warm at pField[r][c] and adjacent cabbage
void PlaceWarm(int** pField, int row, int col, int r, int c);

int main(void)
{
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++)
    {
        int col, row;
        scanf(" %d %d", &col, &row);

        // make row*col size field
        int** field = new int*[row];
        for (int j = 0; j < row; j++)
        {
            field[j] = new int[col];
            for (int k = 0; k < col; k++)
                field[j][k] = CABN_WARMN; // initial state of block
        }
        
        int K; // num of cabbage
        scanf(" %d", &K);
        for (int j = 0; j < K; j++)
        {
            int x, y; // location of cabbage in the field
            scanf(" %d %d", &x, &y);
            field[y][x] = CABY_WARMN; // (x, y) block has cabbage
        }

        int warmCnt = 0; // number of warm has to place
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                if (field[j][k] == CABY_WARMN)
                {
                    PlaceWarm(field, row, col, j, k);
                    warmCnt++;
                }
            }
        }
        printf("%d\n", warmCnt);

        // deallocate memory
        for (int j = 0; j < row; j++)
            delete[] field[j];
        delete[] field;
    }
    return 0;
}

void PlaceWarm(int** pField, int row, int col, int r, int c)
{
    pField[r][c] = CABY_WARMY;
    if (r > 0) // place warm at the above cabbage
    {
        // cabbage is there and warm doesn't visit there yet
        if (pField[r - 1][c] == CABY_WARMN)
            PlaceWarm(pField, row, col, r - 1, c);
    }
    if (r < row - 1) // place warm at the below cabbage
    {
        // cabbage is there and warm doesn't visit there yet
        if (pField[r + 1][c] == CABY_WARMN)
            PlaceWarm(pField, row, col, r + 1, c);
    }
    if (c > 0) // place warm at the left cabbage
    {
        // cabbage is there and warm doesn't visit there yet
        if (pField[r][c - 1] == CABY_WARMN)
            PlaceWarm(pField, row, col, r, c - 1);
    }
    if (c < col - 1) // place warm at the right cabbage
    {
        // cabbage is there and warm doesn't visit there yet
        if (pField[r][c + 1] == CABY_WARMN)
            PlaceWarm(pField, row, col, r, c + 1);
    }
}