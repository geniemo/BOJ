#include <iostream>
using namespace std;

int main(void)
{
    int plugCnt = 1; // initial number of plug
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; i++)
    {
        int plug; // the number of plug in one multitap
        scanf(" %d", &plug);
        plugCnt += (plug - 1);
    }
    printf("%d", plugCnt);
    return 0;
}