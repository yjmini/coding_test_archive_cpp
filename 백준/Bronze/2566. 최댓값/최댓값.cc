#include <iostream>
using namespace std;

int main()
{
	int arr[9][9];
	int maxVal = 0;
	int maxI = 0;
	int maxJ = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (maxVal < arr[i][j])
			{
				maxVal = arr[i][j];
				maxI = i;
				maxJ = j;
			}
		}
	}

	cout << maxVal << '\n';
	cout << maxI + 1 << " " << maxJ + 1;

	return 0;
}