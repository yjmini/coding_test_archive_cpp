#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + 9);

	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum += arr[i];
	}

	sum -= 100;
	int flag = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				arr[i] = 0;
				arr[j] = 0;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << '\n';
	}

	return 0;
}