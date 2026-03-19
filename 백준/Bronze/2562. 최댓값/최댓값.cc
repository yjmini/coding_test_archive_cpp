#include <iostream>
using namespace std;

int main()
{
	int arr[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	int maxVal = 0;
	int maxIdx = 0;

	for (int i = 0; i < 9; i++)
	{
		if (maxVal < arr[i])
		{
			maxVal = arr[i];
			maxIdx = i + 1;
		}
	}

	cout << maxVal << '\n' << maxIdx;

	return 0;
}