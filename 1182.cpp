#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, S; // N: size of seq, S: goal sum
    int cnt = 0;
    scanf(" %d %d", &N, &S);

    vector<int> seq;
    for (int i = 0; i < N; i++)
    {
        int num; scanf(" %d", &num);
        seq.push_back(num);   
    }
    sort(seq.begin(), seq.end()); // sort for get all permutation

    // loop: how many partial sequence's sum is S
    for (int i = 1; i <= N; i++)
    {
        // set for N combination i cases
        vector<int> temp;
        for (int j = 0; j < i; j++)
            temp.push_back(1);
        for (int j = 0; j < N - i; j++)
            temp.push_back(0);
        sort(temp.begin(), temp.end()); // sort for get all permutation

        do // get sum of partial seq that size is i ignoring overlap
        {
            int sum = 0;
            for (int j = 0; j < N; j++)
            {
                if (temp[j] == 1)
                    sum += seq[j];
            }

            if (sum == S) cnt++;
        }
        while (next_permutation(temp.begin(), temp.end())); // break loop when there is no more new combination
    }
    printf("%d", cnt);
    return 0;
}