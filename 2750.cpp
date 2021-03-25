#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
			cin >> arr[i];
	
	for (int i = 0; i < n - 1; i++)
	{
		int tmp = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[tmp])
				tmp = j;
		}
		swap(arr[i], arr[tmp]);
	}
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    delete []arr;
    return 0;
}