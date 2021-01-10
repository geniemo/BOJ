#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    scanf(" %d", &N);
    int cards[static_cast<const int>(N)];
    for (int i = 0; i < N; i++)
        scanf(" %d", &cards[i]);
    sort(cards, cards + N);

    int M;
    scanf(" %d", &M);
    for (int i = 0; i < M; i++)
    {
        int card;
        scanf(" %d", &card);
        printf("%d ", binary_search(cards, cards + N, card));
    }
    
    return 0;
}