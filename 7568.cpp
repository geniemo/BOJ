#include <iostream>
using namespace std;

typedef struct
{
    int weight;
    int height;
    int rank;
} Person;

int main(void)
{
    int numberOfPerson;
    cin >> numberOfPerson;
    Person * arrPtr = new Person[numberOfPerson];
    for (int i = 0; i < numberOfPerson; i++)
        cin >> arrPtr[i].weight >> arrPtr[i].height;

    for (int i = 0; i < numberOfPerson; i++)
    {
        int tallerCnt = 0;
        for (int j = 0; j < numberOfPerson; j++)
            if (arrPtr[j].height > arrPtr[i].height && arrPtr[j].weight > arrPtr[i].weight)
                    tallerCnt++;
        arrPtr[i].rank = tallerCnt + 1;
    }

    for (int i = 0; i < numberOfPerson; i++)
            cout << arrPtr[i].rank << " ";

    delete []arrPtr;

    return 0;           
}